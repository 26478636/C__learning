#include "wmAutoreleasePool.h"

USING_NS_WM;

wmAutoreleasePool::wmAutoreleasePool()
{
    _objects.reserve(100);
}

wmAutoreleasePool::~wmAutoreleasePool()
{
    // clear();
}

void wmAutoreleasePool::addObject(wmKef *object)
{
    _objects.push_back(object);
}

void wmAutoreleasePool::clear()
{
    std::vector<wmRef *> releasings;
    releasings.swap(_objects);
    for (auot obj : releasings)
    {
        obj->release();
    }
}
