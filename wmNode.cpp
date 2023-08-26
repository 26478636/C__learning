#include "wmNode.h"
#include "wmRender.h"
#include "wmDirector.h"
#include "wmScheduler.h"
#include <algorithm>

USING_NS_WM;

// ------------------------------------------------------------------------------------------------
// 构造函数  &&  析构函数
wmNode::wmNode()
    : _name(""), _tag(0), _visible(true), _zotder(0), _x(0), _y(0), _pause(false), _reorderChildDirty(false), _parent(nullptr)
{
}
wmNode::~wmNode() {}
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// 做渲染
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
        int i = 0; // 子节点
        for (; i < _children.size(); i++)
        {
            // 渲染，从负数，到正数
            // 左子树
            // at()访问vector容器的下标
            auto node = _children.at(i);
            if (node && node->_zotder < 0)
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
void wmNode::onEnter()
{
    for (auto child : _children)
    {
        // 子节点也需要onEnter操作
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
    node->_zotder = zorder;
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
    for (auto it = _children.begin(); it != _children.end(); it++)
    {
        // 利用string 进行判断
        if ((*it)->_name.compare(name) == 0)
        {
            it = _children.erase(it);
            // break;
        }
    }
}
void wmNode::removechile(int tag)
{
    for (auto it = _children.begin(); it != _children.end(); it++)
    {
        // 利用id进行判断
        if ((*it)->_tag == tag)
        {
            it = _children.erase(it);
            // break;
        }
    }
}
// ------------------------------------------------------------------------------------------------

// 排序
void wmNode::sortAllChildren()
{
    // 需要重排的话
    if (_reorderChildDirty)
    {
        sortNodes(_children);       // 进行排序
        _reorderChildDirty = false; // 排完之后，返回false
    }
}

void wmNode::scheduleOnce(std::function<void(float)> callback)
{
    // 向谁申请调度 当然是向导演类申请方法了
    wmDirector::instance()->getScheduler();
}
void wmNode::schedule(std::function<void(float)> callback, int repeat, float interval)
{
    // 获取调度
}
void wmNode::scheduleUpdate() {}
void wmNode::unscheduleUpdate() {}