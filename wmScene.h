#ifndef _WM_SCENE_H_
#define _WM_SCENE_H_

// 引入一些宏定义
#include "wmNode.h"
#include "wmDefine.h"

NS_WM_BEGIN

class wmScene : public wmNode
{
    // ------------------------------------------------------------------------------------------------
    void onEnter() override;                 // 有点像开关那个意思
    void onExit() override;                  // 有点像开关那个意思
    void update(float da);                   // 实现调度，希望每帧一调度
    virtual void render(wmRender *wmrender); // 遍历自己的子节点
    // ------------------------------------------------------------------------------------------------
};

NS_WM_END

#endif