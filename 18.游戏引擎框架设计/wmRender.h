#ifndef _WM_RENDER_H_
#define _WM_RENDER_H_

// 一些宏定义
#include "wmDefine.h"

NS_WM_BEGIN

class wmNode; // 渲染的是界面

// 渲染器
class wmRender
{
public:
    // 就这么一个成员函数，渲染器 ，就干这个活
    // 开始渲染
    // ------------------------------------------------------------------------------------------------
    virtual void draw(wmNode *node);
    // ------------------------------------------------------------------------------------------------
};

NS_WM_END
#endif
