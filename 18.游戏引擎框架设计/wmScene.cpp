#include "wmScene.h"

USING_NS_WM;

void wmScene::onEnter()
{
}
void wmScene::onExit()
{
}
void update(float da)
{
}
void wmScene::render(wmRender *render)
{
    // 渲染器render，就要调用visit（遍历函数）
    this->visit(render);
}