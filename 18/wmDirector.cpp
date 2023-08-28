#include <thread>
#include "wmScene.h"
#include "wmRender.h"
#include "wmDirector.h"
#include "wmScheduler.h"
#include "wmAutoreleasePool.h"

USING_NS_WM;

// ------------------------------------------------------------------------------------------------
// 创建一个实例化的导演
wmDirector *_instance = nullptr;
// 实现静态函数功能，相当于初始化的过程，得到一个导演对象
wmDirector *wmDirector::instance()
{
    // 实例化导演身份
    if (_instance == nullptr)
    {
        _instance = new wmDirector();
        // 初始化
        _instance->init();
        return _instance;
    }
}
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// 构造函数  &&  析构函数  &&  init()函数  &&  设置帧率为1
wmDirector::wmDirector() : _runningScene(nullptr),
                           _nextScene(nullptr),
                           _fps(1),
                           _deltaTime(0),
                           _paused(false)
{
}
wmDirector::~wmDirector()
{
    // 一定要做，内存的自动释放
    delete _render;
    delete _scheduler;
    delete _releasepool;
}
bool wmDirector::init()
{
    // 渲染器、调度器、回收器都要在init()函数中，进行初始化
    // 渲染器
    _render = new wmRender();
    // 调度器
    _scheduler = new wmScheduler();
    // 回收器
    _releasepool = new wmAutoreleasePool();

    return true;
}
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// 导演实现的主逻辑

// 切换场景
void wmDirector::runScene(wmScene *scene)
{
    // 从此时开始渲染场景
    _scenes.push_back(scene); // push_back进场景vector中
    _nextScene = scene;       // 设置下一个场景，也是scene
    this->start();
} // 正在执行的场景
void wmDirector::replaceScene(wmScene *scene)
{
    if (_scenes.size() > 0)
    {
        _scenes.pop_back();
    }
    _scenes.push_back(scene);
    _nextScene = scene;
} // 下一帧所替代的场景
void wmDirector::pushScene(wmScene *scene)
{
    _scenes.push_back(scene);
    _nextScene = scene;
} // 推送进场景
void wmDirector::popScene(wmScene *scene)
{
    if (_scenes.size() > 1)
    {
        _scenes.pop_back();
        _nextScene = _scenes.back();
    }
} // 从场景中弹出的

// 场景状态控制
void wmDirector::start()
{
    // 开始启动
    _paused = false;                     // 更新
    _deltaTime = 0;                      // 更新
    gettimeofday(&_lastUpdeta, nullptr); // 更新一下_lastUpdate
    this->mainLoop();                    // 紧接着进入主循环
}
void wmDirector::pause()
{
    if (_paused)
        return;
    _deltaTime = 0; // 计时更新
    _paused = true;
}
void wmDirector::resume()
{
    _paused = false;
} // 恢复之前的状态
void wmDirector::restart() {}

// 场景运行逻辑
void wmDirector::mainLoop()
{
    // 实现主循环
    while (true)
    {
        if (calculateDeltatime())
        { // 控制帧率 1/60
            // 超过一帧范围，绘制图像
            drawScene();
        }
        else
        {
            // 线程休眠，一毫秒
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}
void wmDirector::drawScene()
{
    if (_paused)
        return;

    // 先做场景切换  然后做调度处理  最后要绘制场景

    // 1.先要场景切换
    setNextScene();

    // 2.处理调度scheduler
    // 在这进行update
    _scheduler->update(_deltaTime);

    // 3.绘制scene
    // 判断_runningScene当前是否有值
    if (_runningScene)
    {
        // 渲染当前的场景
        // 在这里，Scene调用的是render方法，所以Scene类中，需要包括render方法
        _runningScene->render(_render);
    }

    // 4.内存自动释放
    _releasePool->clear();

    // 这里我们需要，有一个打印日志
    WMBLOG("----------drawScene-----deltaTime=%f\n----------", _deltaTime);
}
void wmDirector::setNextScene()
{
    if (_nextScene)
    {
        if (_runningScene)
        {
            _runningScene->onExit();
        }
        _runningScene = _nextScene;
        _nextScene = nullptr;
        _runningScene->onEnter();
    }
}
// 计算两帧之间的时间
bool wmDirector::calculateDeltatime()
{
    timeval now; // 目前的时间

    // gettimeofday() 取到当前的一个时间
    if (gettimeofday(&now, nullptr) != 0)
        return false;

    // 计算时间差
    float elapsed = now.tv_sec - _lastUpdeta.tv_sec + (now.tv_usec - _lastUpdeta.tv_usec) / 1000000.0;
    // 判断时间是否溢出
    if (elapsed >= 1.0f / _fps)
    {
        _lastUpdeta = now;
        _deltaTime = elapsed; // 把每帧之间的时间间隔显示出来
        return true;
    }
    return false;
}
// ------------------------------------------------------------------------------------------------
