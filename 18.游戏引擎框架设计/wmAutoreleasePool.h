#ifndef _WM_AUTORELEASE_POOL_H_
#define _WM_AUTORELEASE_POOL_H_

#include "wmDirector.h"
#include <vector>

NS_WM_BEGIN

class wmRef; // 前置声明
class wmAutoreleasePool
{
private:
    // 记录每个对象的引用计数
    std::vector<wmRef *> _objects;

public:
    wmAutoreleasePool();
    ~wmAutoreleasePool();

    void addObject(wmRef *object); // 增加对象
    void clear();                  // 做清空操作
};

NS_WM_END

#endif