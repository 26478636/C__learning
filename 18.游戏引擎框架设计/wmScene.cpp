#include "wmScene.h"

USING_NS_WM;

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

void wmScene::update(float da)
{
}

void wmScene::render(wmRender *wmrender)
{
    // 渲染器render，就要调用visit（遍历函数）
    this->visit(wmrender);
}