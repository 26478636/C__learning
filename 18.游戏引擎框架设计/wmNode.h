#ifndef _WM_NODE_H_
#define _WM_NODE_H_

#include "wmDefine.h"
#include <functional>
#include <algorithm>
#include <string>
#include <vector>

NS_WM_BEGIN

class wmRender;
// 是scene的基类
class wmNode
{
    friend class wmRender; // 设置成友元类

protected:
    // 不想被外界访问的
    // 成员属性
    std::string _name; // 待渲染界面的名字
    int _tag;          // id 地址
    bool _visible;     // 是否可见
    int _Zotder;       // z坐标
    float _x, _y;
    bool _pause;             // 如果不在场景树中，那么不对其进行渲染
    bool _reorderChildDirty; // 是否对该场景树做排序
    // 待渲染界面的存储
    std::vector<wmNode *> _children; // 子节点
    wmNode *_parent;                 // 父节点

public:
    // wmNode *create()
    // {
    //     // 做内存管理
    //     // 把this存入自动回收池进行管理
    // }

    // 新增接口，可以注册Scheduler
    virtual void scheduleOnce(std::function<void(float)> callback);                         // 重复一次
    virtual void schedule(std::function<void(float)> callback, int repeat, float interval); // 重复N次
    virtual void scheduleUpdate();                                                          // 每帧更新
    virtual void unscheduleUpdate();

    // 做渲染
    virtual void visit(wmRender *wmrender); // 遍历
    virtual void draw(wmRender *wmrender);  // 绘制
    virtual void update(float dt);          // 更新调度

    virtual void onEnter(); // 把节点插入到场景时，进行此操作
    virtual void onExit();  // 把节点从场景删除时，进行此操作

    virtual void addChild(wmNode *node, int zorder = 0, int tag = 0); // 新增子节点
    virtual void removeChild(wmNode *child);                          // 删除子节点
    virtual void removechile(const std::string &name);                // 删除子节点
    virtual void removechile(int tag);                                // 删除子节点

protected:
    // 二次构造，同director一样
    wmNode();
    ~wmNode();
    virtual bool init() { return true; }

    // 设计成模板函数类型
    // 排序，排序很重要，别忘了
    void sortAllChildren();
    template <typename _T>
    inline static void sortNodes(std::vector<_T *> &nodes)
    {
        // Zorder只有在wmNode才有，所以先要进行一次校验
        // 校验 wmNode与_T(wmNode派生类)的类型一致
        static_assert(std::is_base_of<wmNode, _T>::value, "wmNode::sortNodes only Accept derived of wmNode!");
        std::sort(std::begin(nodes), std::end(nodes), [](_T *n1, _T *n2)
                  { return n1->ZOrder < n2->ZOrder; })
    }
};

NS_WM_END
#endif