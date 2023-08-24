#include "wmNode.h"
#include <algorithm>

USING_NS_WM;

// 初始化
wmNode::wmNode() : _name(""), _tag(0), _visible(true), _Zotder(0), _x(0), _y(0), _pause(false), _reorderChildDirty(false), _parent(nullptr)
{
}
wmNode::~wmNode() {}

// 各种函数的实现
void wmNode::onEnter()
{
    for (auto child : _children)
    {
        child->onEnter();
    }
}

void wmNode::onExit()
{
    for (auto child : _children)
    {
        child->onExit();
    }
}

void wmNode::addChild(wmNode *node, int zorder = 0, int tag = 0)
{
    // 增加插图，更改画面
    node->_parent = this;
    _children.push_back(node);
    node->_Zotder = zorder;
    node->_tag = tag;
    _reorderChildDirty = true;
}

void wmNode::removeChild(wmNode *child)
{
    // 就简单的删除子节点
    if (_children.empty())
        return;
    auto iter = std::find(_children.begin(), _children.end(), child);
    if (iter != _children.end())
    {
        _children.erase(iter);
    }
}

void wmNode::removechile(const std::string &name)
{
    for (auto iter = _children.begin(); iter != _children.end(); iter++)
    {
        // 利用string 进行判断
        if ((*iter)->_name.compare(name) == 0)
        {
            _children.erase(iter);
            // break;
        }
    }
}

void wmNode::removechile(int tag)
{
    for (auto iter = _children.begin(); iter != _children.end(); iter++)
    {
        // 利用id进行判断
        if ((*iter)->_tag == tag)
        {
            _children.erase(iter);
            // break;
        }
    }
}

void wmNode::visit(wmRender *wmrender)
{
    // 中序遍历
    if (_children.empty())
    {
        // 那就渲染自己
        this->draw(wmrender);
    }
    else
    {
        // 开始中序遍历了
        // 首先需要排序
        sortAllChildren();
        int i = 0;
        for (; i < _children.size(); i++)
        {
            auto node = _children.at(i);
            if (node && node->_Zotder < 0)
            {
                // 开始遍历
                node->visit(wmrender);
            }
            else
            {
                break;
            }
        }
        // 渲染自己啦
        this->draw(wmrender);
        // 渲染右子树
        for (auto it = _children.begin() + i; it != _children.end(); ++it)
        {
            (*it)->visit(wmrender);
        }
    }
}

void wmNode::draw(wmRender *wmrender)
{
    // 查看是否可视化
    if (_visible)
    {
        wmrender->draw(this);
    }
}

void wmNode::update(float dt)
{
}