#include <iostream>
#include "wmScene.h"
#include "wmDirector.h"

USING_NS_WM;

int main()
{
    wmScene *scene = new wmScene();
    scene->setName("wmscene");
    // 创建实例化 然后就可以执行后续功能函数 做测试
    wmDirector::instance()->runScene(scene);

    return 0;
}