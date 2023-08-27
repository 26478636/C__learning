#include "wmScheduler.h"
#include <functional>

NS_WM_BEGIN

// ------------------------------------------------------------------------------------------------
// 构造函数  &&  析构函数
wmScheduler::wmScheduler() {}
wmScheduler::~wmScheduler()
{
    // 需要将三个map清空掉
    for (auto entry : _updateMap)
    {
        delete entry.second;
    }
    for (auto entry : _timerMap)
    {
        delete entry.second;
    }
    for (auto entry : _repeatMap)
    {
        delete entry.second;
    }
}
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// update()函数     dt为调度时间
void wmScheduler::update(float dt)
{
    // 三种情况
    // 每一帧去更新的  遍历每帧都要去调度的对象
    for (auto entry : _updateMap)
    {
        // 如果，不暂停执行
        if (!entry.second->paused)
        {
            // 调用callback()函数
            entry.second->callback(dt);
        }
    }

    // 重复一次  遍历重复调度一次的对象
    for (auto entry : _timerMap)
    {
        if (!entry.second->paused)
        {
            entry.second->callback(dt);
        }
        // 做好内存的释放
        delete entry.second;
    }
    _timerMap.clear();

    // 重复N次  遍历重复调度N次的对象
    bool isFix = false; // 标记位，判断是否repeatN次
    // 这里没有it++很巧妙
    for (auto it = _repeatMap.begin(); it != _repeatMap.end();)
    {
        auto entry = *it;
        if (!entry.second->paused)
        {
            // 时间到了，我们去做调度
            entry.second->time -= dt;
            if (entry.second->time <= 0.0f)
            {
                entry.second->time = entry.second->interval;
                entry.second->callback(dt);
                if (entry.second->repeat != -1)
                {
                    entry.second->repeat--;
                    if (entry.second->repeat == 0)
                    {
                        auto p = it->second;
                        _repeatMap.erase(it); // it = _repeatMap.erase(it);
                        delete p;
                        isFix = true;
                    }
                }
            }
        }
        if (isFix)
            ++it; // *****这里老师的逻辑，应该是写错了*****
    }
}
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// schedule()函数 调度器
void wmScheduler::schedule(std::function<void(float)> callback,
                           float interval, unsigned int repeat, void *target, bool paused)
{
    _TimerEntry *entry = new _TimerEntry{
        target, callback, paused, repeat, 0, interval};
    if (repeat = 0)
    {
        // 重复一次
        _timerMap[target] = entry;
    }
    else
    {
        // 重复N次
        _repeatMap[target] = entry;
    }
}
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
void wmScheduler::schedulePerFrame(const std::function<void(float)> &callback, void *target, bool paused)
{
    // 构造一个对象
    _UpdateEntry *entry = new _UpdateEntry{
        target, callback, paused};
}
void wmScheduler::unschedulerUpdate(void *target)
{
    auto it = _updateMap.find(target);
    if (it != _updateMap.end())
    {
        // 内存释放
        delete it->second;
        _updateMap.erase(it);
    }
}
// ------------------------------------------------------------------------------------------------

NS_WM_END