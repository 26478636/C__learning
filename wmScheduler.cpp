#include "wmScheduler.h"
#include <functional>

NS_WM_BEGIN

wmScheduler::wmScheduler() {}

wmScheduler::~wmScheduler()
{
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

// dt 调度时间
void wmScheduler::update(float dt)
{
    // 三种情况
    // 每一帧去更新的
    for (auto entry : _updateMap)
    {
        // 如果，不暂停执行
        if (!entry.second->paused)
        {
            entry.second->callback(dt);
        }
    }

    // 重复一次
    for (auto entry : _timerMap)
    {
        if (!entry.second->paused)
        {
            entry.second->callback(dt);
        }
        delete entry.second;
    }
    _timerMap.clear();

    // 重复N次
    bool isFix = false;
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
        if (!isFix)
            ++it;
    }
}

void wmScheduler::schedule(std::function<void(float)> callback,
                           float interval, unsigned int repeat, void *target, bool paused = false)
{
    _TimerEntry *entry = new _TimerEntry{
        target, callback, paused, repeat, 0, interval};
    if (repeat = 0)
    {
        _timerMap[target] = entry;
    }
    else
    {
        _repeatMap[target] = entry;
    }
}

void wmScheduler::schedulePerFrame(const std::function<void(float)> &callback, void *target, bool paused)
{
    _UpdateEntry *entry = new _UpdateEntry{
        target, callback, paused};
}
void wmScheduler::unschedulerUpdate(void *target)
{
    auto it = _updateMap.find(target);
    if (it != _updateMap.end())
    {
        delete it->second;
        _updateMap.erase(it);
    }
}

NS_WM_END