#include "wmRef.h"
#include "wmDirector.h"
#include "wmAutoreleasePool.h"

USING_NS_WM;

wmRef::wmRef() : _reference(1)
{
}
wmRef::~wmRef()
{
}

wmRef *wmRef ::autorelease()
{
    wmDirector::instance()->getAutorelease()->addObject(this);
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
        delete this;
    }
}