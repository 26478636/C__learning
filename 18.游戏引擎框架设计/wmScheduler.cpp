#include "wmScheduler.h"

NS_WM_BEGIN

void wmScheduler::update(float dt)
{
    for (auto entry::_updateMap)
    {
        if (!entry.second->paused)
        {
            entry.second->callback(dt);
        }
    }

    for (auto entry::_timerMap)
    {
        if (!entry.second->paused)
        {
            entry.second->callback(dt);
        }
    }
    _timerMap.clear();

    bool isFix = false;
    for (auto it = _repeatMap.begin(); it != _repeatMap.end();)
    {
        auto entry = *it;
        if (!entry.second->paused)
        {
            entry.second->timr -= dt;
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
    }
}

NS_WM_END