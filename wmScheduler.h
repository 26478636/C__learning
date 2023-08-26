#ifndef _WM_SCHEDULER_H_
#define _WM_SCHEDULER_H_

#include <functional>
#include <unordered_map>
#include "wmDefine.h"

NS_WM_BEGIN

// 两类可调度对象
// 每帧一调度
struct _UpdateEntry
{
    void *target; // 调度的是哪一个对象
    // function函数 返回值void 参数类型 float
    std::function<void(float)> callback; // 是哪个函数
    bool paused;                         // target 不在场景树当中，不做调度
};

// 按照自己的想法去调度
// 相当于定时器
struct _TimerEntry
{
    void *target;
    std::function<void(float)> callback;
    bool paused;
    unsigned int repeat; // 重复次数
    float time;          // 延迟时间
    float interval;      // 间隔时间，固定的
};

class wmScheduler
{
private:
    // 成员属性
    // 三种不同的调度
    std::unordered_map<void *, _UpdateEntry *> _updateMap; // 每一帧去调度
    // 按照自己的想法去调度
    // 相当于定时器
    std::unordered_map<void *, _TimerEntry *> _repeatMap; // 重复N次
    std::unordered_map<void *, _TimerEntry *> _timerMap;  // 重复1次

public:
    void update(float dt); // update方法

    // ***模板方法一定要实现在头文件里***
    template <class T>
    // 重复一次
    void scheduleOnce(T *target, std::function<void(float)> callback, bool paused = false)
    {
        this->schedule(callback, 0.0f, 0, target, paused);
    }

    template <class T>
    void schedule(T *target, std::function<void(float)> callback,
                  float interval, unsigned int repeat, bool paused = false)
    {
        this->schedule(callback, interval, repeat, target, paused);
    }

    void schedule(std::function<void(float)> callback,
                  float interval, unsigned int repeat, void *target, bool paused = false);

    template <class T>
    // 每一帧去调用
    void scheduleUpdate(T *target, bool paused)
    {
        this->schedulePerFrame([target](float dt)
                               { target->update(dt); },
                               target, paused);
    }

    void schedulePerFrame(const std::function<void(float)> &callback, void *target, bool paused);
    void unschedulerUpdate(void *target);
};

NS_WM_END

#endif