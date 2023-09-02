#ifndef _WM_NODE_H_
#define _WM_NODE_H_

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include "wmRef.h"
#include "wmVector.h"
#include "wmDefine.h"
#include "wmDirector.h"

NS_WM_BEGIN

class wmRender; // 渲染器

// *****wmNode是树形结构的基类*****
class wmNode : public wmRef
{

    friend class wmRender; // 将渲染器设置成友元类

protected:
    // 不想被外界访问的
    // ------------------------------------------------------------------------------------------------
    // 成员属性
    std::string _name; // Node名字
    int _tag;          // id 地址
    bool _visible;     // 是否可见
    int _zorder;       // z坐标
    float _x, _y;
    bool _pause;             // 如果该Node不在场景树中，那么不对其进行渲染
    bool _reorderChildDirty; // 是否对该场景树做重排
    // 这里的_children，进行addChild()和removechild()时，需要自动进行retain()和release()操作
    vector<wmNode *> _children; // 子节点  这个需要被释放  假设1：vector为STL库中的容器，则需要被释放
                                //                       假设2：重写vector，不需要被释放了，有这个析构函数，所以不用
    wmNode *_parent;            // 父节点
    // ------------------------------------------------------------------------------------------------

public:
    // 为了设置名字
    inline void setName(std::string name) { _name = name; }
    void pause();  // 为了设置_pause;
    void resume(); // 为了设置_pause;

    // ------------------------------------------------------------------------------------------------
    // 定义宏
    CREATE(wmNode);

    // wmNode *creat()
    // {
    //     // 做内存管理
    //     // 把this存入自动回收池进行管理
    //     wmNode *node = new wmNode();
    //     if (node->init())
    //     {
    //         node->autorelease(); // 丢到内存的自动释放池当中去
    //         return node;
    //     }
    //     return nullptr;
    // }
    // ------------------------------------------------------------------------------------------------

    // ------------------------------------------------------------------------------------------------
    // wmNode类中，**新增接口**，为了可以注册Scheduler
    // 在该节点处，可以知道，该节点是什么调度(每帧一调度，还是自定义的调度方法)
    virtual void scheduleOnce(std::function<void(float)> callback);                         // 重复一次
    virtual void schedule(std::function<void(float)> callback, int repeat, float interval); // 重复N次
    virtual void scheduleUpdate();                                                          // 每帧更新
    virtual void unscheduleUpdate();
    // ------------------------------------------------------------------------------------------------

    // ------------------------------------------------------------------------------------------------
    // 做渲染
    virtual void visit(wmRender *wmrender); // 遍历
    virtual void draw(wmRender *wmrender);  // 绘制
    virtual void update(float dt);          // 做相关的调度

    virtual void onEnter(); // 把节点插入到场景时，第一次进行操作时，调用这个函数
    virtual void onExit();  // 把节点从场景删除时，调用这个函数

    virtual void addChild(wmNode *node, int zorder = 0, int tag = 0); // 新增子节点  先设置了一些默认参数
    virtual void removeChild(wmNode *child);                          // 删除子节点
    virtual void removechile(const std::string &name);                // 删除子节点
    virtual void removechile(int tag);                                // 删除子节点
    // ------------------------------------------------------------------------------------------------

protected:
    // ------------------------------------------------------------------------------------------------
    // 不希望外部访问，不希望在这里被new，用create()做内存的自动管理
    // 二次构造，同director一样wmNode();
    wmNode();
    ~wmNode();
    virtual bool init() { return true; }

    // visit()遍历之前，需要先做排列，排列是根据_zorder的大小来排列
    // 设计成模板函数类型，模板函数必须要出现在头文件里
    void sortAllChildren();
    template <typename _T>
    inline static void sortNodes(vector<_T *> &nodes)
    {
        // _zorder只有在wmNode才有，所以可以先进行一次校验
        // 校验wmNode与_T(wmNode派生类)的类型是否一致
        static_assert(std::is_base_of<wmNode, _T>::value, "wmNode::sortNodes only Accept derived of wmNode!");
        std::sort(std::begin(nodes), std::end(nodes), [](_T *n1, _T *n2)
                  { return n1->_zorder < n2->_zorder; });
    }
    // ------------------------------------------------------------------------------------------------
};

NS_WM_END
#endif