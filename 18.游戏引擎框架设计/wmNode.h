#ifndef _WM_Node_HE_
#define _WM_Node_HE_

#include "wmDefine.h"
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
NS_WM_BEGIN

class wmRender;
class wmNode
{
    friend class wmRender;

public:
    // wmNode *create()
    // {
    //     // 做内存管理
    //     // 把this存入自动回收池进行管理
    // }

    virtual void scheduleOnce(std::function<void(float)> callback);
    virtual void schedule(std::function<void(float)> callback, int repeat, float time);
    virtual void scheduleUpdate();
    virtual void unscheduleUpdate();

    virtual void onEnter(); // 插入节点
    virtual void onExit();  // 删除节点

    virtual void addChild(wmNode *node, int Zorder = 0, int tag = 0); // 新增子节点
    virtual void removeChild(wmNode *child);                          // 删除子节点
    virtual void removechile(const std::string &name);                // 删除子节点
    virtual void removechile(int tag);                                // 删除子节点

public:
    virtual void visit(wmRender *render); // 遍历
    virtual void draw(wmRender *render);  // 绘制
    virtual void update(float dt);        // 更新调度

protected:
    wmNode();
    ~wmNode();
    virtual bool init() { return true; }

    // 设计成模板函数类型
    // 排序，排序很重要，别忘了
    void sortAllChildren();
    template <typename _T>
    inline static void sortNodes(std::vector<_T *> &nodes){
        // 校验
        static_assert(std::is_base_of<wmNode, _T>::value, "不知所云")
            std::sort(std::begin(nodes), std::end(nodes), [](_T *n1, _T *n2)
                      { return n1->ZOrder < n2->ZOrder; })}

    // 不想被外界访问的
    // 待渲染的界面
    std::string _name;
    int _tag;      // id 地址
    bool _visible; // 是否可见
    int _Zotder;   // z坐标
    float _x, _y;
    bool _pause;             // 如果不在场景树中，那么不对其进行渲染
    bool _reorderChildDirty; // 是否对该场景树做排序

    // 待渲染界面的存储
    std::vector<wmNode *> _children;
    wmNode *_parent;
};

NS_WM_END
#endif