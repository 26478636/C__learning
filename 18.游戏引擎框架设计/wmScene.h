#ifndef _WM_SCENE_H_
#define _WM_SCENE_H_

// 引入一些宏定义
#include "wmDefine.h"
#include "wmNode.h"

NS_WM_BEGIN

class wmScene : public wmNode
{
    void onEnter() override;
    void onExit() override;
    void update(float da);
    virtual void render(wmRender *render);
};

NS_WM_END

#endif