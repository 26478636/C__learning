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

void wmScheduler::update(float dt)
{
    // 每一帧去更新的
    for (auto entry : _updateMap)
    {
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
                        it = _repeatMap.erase(it);
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

void wmScheduler::scheduler(std::function<void(float)> callback,
                            float interval, unsigned int repeat, void *target, bool paused = false)
{
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
    }
}

NS_WM_END