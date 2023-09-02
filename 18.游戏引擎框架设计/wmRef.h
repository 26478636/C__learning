#ifndef _WM_REF_H
#define _WM_REF_H
#include "wmDefine.h"

NS_WM_BEGIN

// *****wmRef 专门做引用计数的*****
class wmRef
{
private:
    // 引用计数
    unsigned int _reference;

protected:
    // 不想让外部进行构造的
    wmRef();
    virtual ~wmRef();

public:
    // 管理内存的自动释放池，当_reference=0时，做内存的自动释放
    wmRef *autorelease();
    // 引用计数+1
    void retain();
    // 引用计数-1
    void release();
};

NS_WM_END

#endif