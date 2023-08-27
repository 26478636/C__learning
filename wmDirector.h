#ifndef _WM_DIRECTOR_H_
#define _WM_DIRECTOR_H_

#include "wmDefine.h" // 引入一些宏定义
#include <vector>
#include <sys/time.h> // 系统函数 为了计算时间

using namespace std;

NS_WM_BEGIN

// 各种前置声明
class wmScene;           // 场景类
class wmRender;          // 渲染器
class wmScheduler;       // 调度器
class wmAutoreleasePool; // 内存释放池

class wmDirector
{

private:
    // ------------------------------------------------------------------------------------------------
    // 导演的一些属性
    // 场景
    // 丢到内存释放池，做内存的自动释放
    vector<wmScene *> _scenes; // 一些场景
    wmScene *_runningScene;    // 当前场景
    wmScene *_nextScene;       // 下一场景

    // 绘制图形
    // 渲染器
    wmRender *_render;
    // 调度器 做逻辑处理
    // 在每一帧的时候，做update调度......
    wmScheduler *_scheduler;
    // 自动内存释放
    wmAutoreleasePool *_releasepool;

    // 帧率
    float _fps;          // 帧率
    float _deltaTime;    // 时间增量，两帧之间的时间；假设帧率为60，超过1/60秒，调用drawScene()来绘制场景
    timeval _lastUpdeta; // timeval为一个结构体，为了便捷计算时间
    bool _paused;        // 判断场景是否停止
    // ------------------------------------------------------------------------------------------------

public:
    // 导演实现的主逻辑
    // ------------------------------------------------------------------------------------------------
    // 切换场景
    void runScene(wmScene *scene); // 场景创建出来，并作显示
    // 切换方式分为两种：1）replace形式  2）push形式
    void replaceScene(wmScene *scene); // 被下一帧所替代的场景
    void pushScene(wmScene *scene);    // 推送进场景
    void popScene(wmScene *scene);     // 从场景中弹出的

    // 场景状态控制
    void start();
    void pause();
    void resume(); // 恢复
    void restart();

    // 场景运行逻辑
    void mainLoop();           // 主循环
    void drawScene();          // 绘制场景
    void setNextScene();       // 判断下一个场景是否有值，如果有值做自动切换
    bool calculateDeltatime(); // 计算两帧之间的时间 超过1/60秒，渲染下一帧
    // ------------------------------------------------------------------------------------------------

public:
    // 创建静态方法  实例化导演的身份
    static wmDirector *instance();

    // 为什么两次构造函数，为了避免失败
    // 开辟内存空间，这一部分不去做太过复杂的逻辑
    wmDirector();
    ~wmDirector();
    // 创建助手，创建场景，维护调度队列等...
    bool init();

    // ------------------------------------------------------------------------------------------------
    // *****因为调度是导演类管理的，所以向导演类申请调度的方法*****
    wmScheduler *getScheduler() { return _scheduler; }
    // ------------------------------------------------------------------------------------------------
};

NS_WM_END

#endif