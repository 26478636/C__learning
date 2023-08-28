#ifndef _WM_AUTORELEASE_POOL_H_
#define _WM_AUTORELEASE_POOL_H_

#include "wmDirector.h"
#include <vector>

NS_WM_BEGIN

class wmRef;
class wmAutoreleasePool
{
private:
    std::vector<wmRef *> _objects;

public:
    wmAutoreleasePool();
    ~wmAutoreleasePool();
};

NS_WM_END

#endif