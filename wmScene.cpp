#include "wmScene.h"

USING_NS_WM;

// ------------------------------------------------------------------------------------------------
void wmScene::onEnter()
{
    // 调用基类的 onEnter()
    wmNode::onEnter();
}
void wmScene::onExit()
{
    // 调用基类的 onExit()
    wmScene::onExit();
}
// 希望每一帧，都调度update方法
// 调度update方法，需要的导演类中进行触发的
void wmScene::update(float dt)
{
}
void wmScene::render(wmRender *wmrender)
{
    // 渲染器render，就要调用visit（遍历函数）
    this->visit(wmrender);
}
// ------------------------------------------------------------------------------------------------
