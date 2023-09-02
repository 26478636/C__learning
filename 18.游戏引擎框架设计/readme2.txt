// ------------------------------------------------------------------------------------------------
内存的自动回收机制(仿照java原理)

c++: shared-ptr做内存的自动维护

java: 所有对象继承至object(基类)，(在基类当中实现**引用计数**的功能，以便内存的自动释放)

导演类，有主循环(mainLoop)，可以在这里做内存的自动释放(利用好引用计数)

// 内存的自动释放池，就做以下的事情
A new -> ref=1 (引用计数+1)
--ref -> ref=0(当ref=0时) -> delete

// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
wmScene *scene = new wmScene();  scene->setName("wmscene");  wmDirector::instance()->runScene(scene);

// 实现的逻辑

// 1
wmDirector::runScene -> wmDirector::start -> wmDirector::mainLoop ->
wmDirector::drawScene -> wmDirector::setNextScene -> wmScene::onExit ->
wmNode::scheduleUpdate -> wmScheduler::scheduleUpdate -> wmScene::update (做了场景切换 pushScene)->

// 2
wmScheduler::update(执行callback()) -> 

// 3
wmScene::render(执行渲染) ...

// 4
wmAutoreleasePool::clear(释放内存)
// ------------------------------------------------------------------------------------------------
