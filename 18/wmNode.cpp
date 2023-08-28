#include "wmNode.h"
#include "wmRender.h"
#include "wmDirector.h"
#include "wmScheduler.h"
#include <algorithm>

USING_NS_WM;

// ------------------------------------------------------------------------------------------------
// 构造函数  &&  析构函数
wmNode::wmNode()
    : _name(""),
      _tag(0),
      _visible(true),
      _zorder(0),
      _x(0),
      _y(0),
      _pause(false),
      _reorderChildDirty(false),
      _parent(nullptr)
{
    WMBLOG("==========wmNdoe-----constructor %p!\n", this);
}
wmNode::~wmNode()
{
    WMBLOG("==========wmNdoe-----destructor %p!\n", this);
}
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// 遍历之前需要现做排序
// 排序
void wmNode::sortAllChildren()
{
    // 判断是否需要重排
    if (_reorderChildDirty)
    {
        sortNodes(_children);       // 进行排序
        _reorderChildDirty = false; // 排完之后，返回false
    }
}
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
            // 渲染左子树
            // at()访问vector容器的下标
            auto node = _children.at(i);
            if (node && node->_zorder < 0)
            {
                // 开始遍历
                node->visit(wmrender);
            }
            else
                break;
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
    // 新场景把老场景盖住之后，老场景就不应该再调用update()方法，之前的node暂停
    _pause = true;
    for (auto child : _children)
    {
        // 子节点也需要onEnter操作
        child->onEnter();
    }
}
void wmNode::onExit()
{
    _pause = true;
    for (auto child : _children)
    {
        child->onExit();
    }
}
void wmNode::addChild(wmNode *node, int zorder, int tag)
{
    // 增加插图，更改画面
    node->_parent = this;
    _children.push_back(node);
    node->_zorder = zorder;
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

// ------------------------------------------------------------------------------------------------
// 重复调度1次
void wmNode::scheduleOnce(std::function<void(float)> callback)
{
    // 向谁申请调度 当然是向导演类申请方法了
    // 向导演类申请调度了
    wmDirector::instance()->getScheduler()->scheduleOnce(this, [callback](float dt)
                                                         { callback(dt); });
}
// 重复调度N次
void wmNode::schedule(std::function<void(float)> callback, int repeat, float interval)
{
    // 获取调度
    wmDirector::instance()->getScheduler()->schedule(
        this, [callback](float dt)
        { callback(dt); },
        interval, repeat, false);
}
void wmNode::scheduleUpdate()
{
    wmDirector::instance()->getScheduler()->scheduleUpdate(this, _pause);
}
void wmNode::unscheduleUpdate()
{
    wmDirector::instance()->getScheduler()->unschedulerUpdate(this);
}
// ------------------------------------------------------------------------------------------------
