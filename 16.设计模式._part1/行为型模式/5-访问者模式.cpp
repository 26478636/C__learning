// visitor
#include <iostream>

using namespace std;

class Node; // 被访问对象
// 创建访问者基类
class Visitor
{
public:
    // node为访问对象
    virtual void visitor(Node *_node) = 0;
};
class Node
{
public:
    // 可以接收访问器类型
    virtual void accept(Visitor *_visitor) = 0;
};

// 被访问对象的子类
class A_Node : public Node
{
public:
    friend class A_Visitor;

protected:
    string s;

public:
    // 默认构造函数
    A_Node()
    {
        s = "hello kaikeba";
    }
    void accept(Visitor *_visitor)
    {
        _visitor->visitor(this);
    }
};

class B_Node : public Node
{
public:
    friend class B_Visitor;

protected:
    string s;

public:
    // 默认构造函数
    B_Node()
    {
        s = "你是正常人民么";
    }
    void accept(Visitor *_visitor)
    {
        _visitor->visitor(this);
    }
};

// 派生访问器
class A_Visitor : public Visitor
{
public:
    void visitor(Node *_node)
    {
        A_Node *P = dynamic_cast<A_Node *>(_node);
        if (P)
        {
            cout << "输出" << P->s.c_str() << endl;
        }
    }
};

class B_Visitor : public Visitor
{
public:
    void visitor(Node *_node)
    {
        B_Node *P = dynamic_cast<B_Node *>(_node);
        if (P)
        {
            cout << "输出" << P->s.c_str() << endl;
        }
    }
};

int main()
{
    A_Node *nodeA = new A_Node();
    B_Node *nodeB = new B_Node();
    A_Visitor *visitorA = new A_Visitor();
    B_Visitor *visitorB = new B_Visitor();
    visitorA->visitor(nodeA);
    visitorB->visitor(nodeB);
    delete visitorA;
    delete visitorB;
    delete nodeA;
    delete nodeB;

    return 0;
}