#include <stdio.h>
#include <iostream>
#include "wmNode.h"
#include "wmScene.h"
#include "wmDirector.h"

USING_NS_WM;

int main()
{
    wmScene *scene = wmScene::create(); // 会自动插入到内存的自动释放池中
    scene->setName("wmscene");
    for (int i = 0; i < 5; i++)
    {
        auto node = wmNode::create();
        char name[100];
        sprintf(name, "%s%d", "wmNode", i - 2);
        node->setName(name);
        scene->addChild(node, i - 2); // -2,-1,0,1,2
        // 这里的addChild操作，需要引用计数+1，即调用retain()
    }
    // 创建实例化 然后就可以执行后续功能函数 做测试
    wmDirector::instance()->runScene(scene);

    return 0;
}