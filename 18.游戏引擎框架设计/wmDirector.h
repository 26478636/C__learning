#ifndef _WM_DIRECTOR_H_
#define _WM_DIRECTOR_H_

#include "wmDefine.h" // 引入一些宏定义
#include <vector>
#include <sys/time.h>

using namespace std;

NS_WM_BEGIN

class wmScene; // 场景类
class wmRender;
class wmScheduler;
class wmAutoreleasePool; // 内存释放池
// 导演的头文件
class wmDirector
{

private:
    // 场景
    vector<wmScene *> _scenes;
    wmScene *_runningScene;
    wmScene *_nextScene;

    // 丢到内存释放池，做内存的自动释放
    // 绘制图形 渲染器
    wmRender *_render;
    // 调度器
    wmScheduler *_scheduler;
    // 自动内存释放
    wmAutoreleasePool *_releasepool;

    // 帧率
    float _fps;          // 帧率
    float _deltaTime;    // 时间增量，两帧之间的时间
    timeval _lastUpdeta; // timeval为一个结构体，为了便捷计算时间
    bool _paused;        // 判断场景是否停止

public:
    // 导演真正可以做的工作
    // 切换场景
    void runScene(wmScene *scene); // 正在执行的场景
    // 切换方式分为两种：1）replace形式  2）push形式
    void replaceScene(wmScene *scene); // 下一帧所替代的场景
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
    bool calculateDeltatime(); // 判断时间是否溢出，比如一秒，如果溢出，推送图片进去

public:
    // 创建静态方法  实例化导演的身份
    static wmDirector *instance();

    // 为什么两次构造函数，为了避免失败
    // 开辟内存空间
    wmDirector();
    ~wmDirector();
    // 创建助手，创建场景，维护场景队列等...
    bool init();
};

NS_WM_END

#endif