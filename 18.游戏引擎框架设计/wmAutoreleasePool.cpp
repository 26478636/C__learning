#include "wmRef.h"
#include "wmAutoreleasePool.h"

USING_NS_WM;

wmAutoreleasePool::wmAutoreleasePool()
{
    // 创建100个大小的空间
    _objects.reserve(100);
}

wmAutoreleasePool::~wmAutoreleasePool()
{
    clear();
}

void wmAutoreleasePool::addObject(wmRef *object)
{
    // 增加对象
    _objects.push_back(object);
}

void wmAutoreleasePool::clear()
{
    std::vector<wmRef *> releasings;
    releasings.swap(_objects);
    for (auto obj : releasings)
    {
        obj->release();
    }
}
