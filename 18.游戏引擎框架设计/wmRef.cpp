#include "wmRef.h"
#include "wmDirector.h"
#include "wmAutoreleasePool.h"

USING_NS_WM;

// ------------------------------------------------------------------------------------------------
wmRef::wmRef() : _reference(1)
{
    // 引用计数初始化为1
}
wmRef::~wmRef()
{
}
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
wmRef *wmRef ::autorelease()
{
    // push_back()进，池中
    wmDirector::instance()->getAutoreleasePool()->addObject(this);
    return this;
};
void wmRef::retain()
{
    ++_reference;
}
void wmRef::release()
{
    --_reference;
    if (_reference == 0)
    {
        delete this; // 判断什么时候清空
    }
}
// ------------------------------------------------------------------------------------------------
