#ifndef _WM_REF_H
#define _WM_REF_H
#include "wmDefine.h"

NS_WM_BEGIN

class wmRef
{
private:
    unsigned int _reference;

protected:
    wmRef();
    virtual ~wmRef();

public:
    wmRef *autorelease();
    void retain();
    void release();
};

NS_WM_END

#endif