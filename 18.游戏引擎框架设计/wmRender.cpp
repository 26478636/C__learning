#include "wmRender.h"
#include "wmNode.h"

USING_NS_WM;

void wmRender::draw(wmNode *node)
{
    // 调用图形库，对界面进行渲染
    WMBLOG("Render Node x=%f, y=%f \n", node->_x, node->_y);
}