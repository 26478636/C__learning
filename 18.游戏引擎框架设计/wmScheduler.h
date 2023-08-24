#ifndef _WM_SCHEDULER_H_
#define _WM_SCHEDULER_H_

#include <functional>
#include <unordered_map>
#include "wmDefine.h"

NS_WM_BEGIN

struct _UpdateEntry
{
    void *target;
    std::function<void(float)> callback;
    bool paused;
};

struct _TimeEntry
{
    void *target;
    std::function<void(float)> callback;
    bool paused;
    unsigned int repeat;
    float time;     // 延迟时间
    float interval; // 间隔时间
};

class wmScheduler
{
private:
    std::unordered_map<void *, _UpdateEntry> _updateMap;
    std::unordered_map<void *, _TimeEntry> _repeatMap; // 重复N次
    std::unordered_map<void *, _TimeEntry> _timeMap;   // 重复1次
};

NS_WM_END

#endif