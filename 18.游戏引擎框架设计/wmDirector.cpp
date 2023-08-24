#include <thread>
#include "wmDirector.h"

USING_NS_WM;

// 创建一个实例化的导演
wmDirector *_instance = nullptr;

// 实现静态函数功能
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

// 一些个默认初始化
// 设置帧率为60
wmDirector::wmDirector() : _runningScene(nullptr),
                           _nextScene(nullptr),
                           _fps(60),
                           _deltaTime(0),
                           _paused(false)
{
}

wmDirector::~wmDirector() {}

bool wmDirector::init()
{
    return true;
}

// 实现一些函数的具体功能
void wmDirector::runScene(wmScene *scene)
{
    // 从此时开始渲染场景
    this->start();
} // 正在执行的场景

void wmDirector::replaceScene(wmScene *scene) {} // 下一帧所替代的场景
void wmDirector::pushScene(wmScene *scene) {}    // 推送进场景
void wmDirector::popScene(wmScene *scene) {}     // 从场景中弹出的

// 场景状态控制
void wmDirector::start()
{
    // 开始启动
    _paused = false;                     // 更新
    _deltaTime = 0;                      // 更新
    gettimeofday(&_lastUpdeta, nullptr); // 初始化一下_lastUpdate
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
} // 恢复

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
    {
        return;
    }

    // 场景切换
    setNextScene();

    // 处理调度scheduler

    // 绘制scene
    if (_runningScene)
    {
        // 进行渲染
        // _runningScene->wmrender(_wmrender);
    }

    // 内存自动释放

    // 这里我们需要，有一个打印日志
    WMBLOG("----------drawScene-----deltaTime=%f\n----------", _deltaTime);

} // 绘制场景

void wmDirector::setNextScene() {}

// 计算两帧之间的时间
bool wmDirector::calculateDeltatime()
{
    timeval now; // 目前的时间

    // gettimeofday() 得到一个准确时间
    if (gettimeofday(&now, nullptr) != 0)
    {
        return false;
    }

    // 计算时间差
    float elapsed = now.tv_sec - _lastUpdeta.tv_sec + (now.tv_usec - _lastUpdeta.tv_usec) / 1000000.0;
    // 判断时间是否溢出
    if (elapsed >= 1.0f / _fps)
    {
        _lastUpdeta = now;
        _deltaTime = elapsed;
        return true;
    }
    return false;
}
