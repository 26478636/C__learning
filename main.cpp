#include <iostream>
#include "wmDirector.h"

USING_NS_WM;

int main()
{

    // 创建实例化 然后就可以执行后续功能函数 做测试
    wmDirector::instance()->runScene(nullptr);

    return 0;
}