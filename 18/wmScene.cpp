#include "wmScene.h"

USING_NS_WM;

// ------------------------------------------------------------------------------------------------
void wmScene::onEnter()
{
    WMBLOG("==========wmScene - onEnter address = %p\n", this);
    // 调用基类的 onEnter()
    wmNode::onEnter();
    this->scheduleUpdate();
}
void wmScene::onExit()
{
    WMBLOG("==========wmScene - onExit address = %p\n", this);
    // 调用基类的 onExit()
    wmScene::onExit();
    this->scheduleUpdate();
}
void wmNode::pause()
{
    _pause = true;
    for (auto child : _children)
    {
        child->pause();
    }
    wmDirector::instance()::getScheduler()->pause();
}
void wmNode::resume()
{
    _pause = false;
    for (auto chile : _children)
    {
        child->pause();
    }
    wmDirector::instance()::getScheduler()->resume();
}
// 希望每一帧，都调度update方法
// 调度update方法(update就是做了调度，但是没有渲染)，需要的导演类中进行触发的
void wmScene::update(float dt)
{
    WMBLOG("==========wmScene - update %f address=%p\n", dt, this);

    auto node = wmNode::creat()

    // // 创建一个新场景
    // auto scene = new wmScene();
    // scene->setName("scene2");
    // // 这里做了一个场景切换
    // if (scene->init())
    // {   // 判断是否创建成功
    //     wmDirector::instance()->pushScene(scene); // 做push操作时，都会调用onEnter()和onExit()方法
    // }
}
void wmScene::render(wmRender *wmrender)
{
    // 渲染器render，就要调用visit（遍历函数）
    this->visit(wmrender);
}
// ------------------------------------------------------------------------------------------------
