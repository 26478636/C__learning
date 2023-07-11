#include <iostream>

using namespace std;

// 执行命令的接收者
class Receiver
{
public:
    // 接受命令产生的动作
    virtual void action()
    {
        cout << "执行动作" << endl;
    }
};

class A_Receiver : public Receiver
{
public:
    void action()
    {
        cout << "执行动作A" << endl;
    }
};

class Command
{
protected:
    // 执行命令的对象
    Receiver *_rece;

public:
    // 有参构造
    Command(Receiver *rece) : _rece(rece) {}
    virtual void setReceiver(Receiver *rece) { _rece = rece; }
    // 具体的命令如何
    virtual void doCommand(int n) = 0;
};

class A_Command : public Command
{
protected:
    Receiver *_rece2;

public:
    using Command::Command;

    A_Command(Receiver *rece1, Receiver *rece2) void setReceiver(Receiver *rece2)
    {
        _rece2 = rece2;
    }
    void doCommand(int n)
    {
        if (n == 0)
            _rece->action();
        else
            _rece2->action();
    }
};

class B_Command : public Command
{
public:
    void doCommand(int n)
    {
        cout << "B_Command输出" << endl;
        _rece->action();
    }
};

// 调用者
class Invoker
{
protected:
    Command *_command; // 具体调用的命令
public:
    // 默认构造
    Invoker() : _command(nullptr) {}
    // 设置命令
    void setCommand(Command *command)
    {
        _command = command;
    }
    // 调用该命令
    void beginCommand()
    {
        if (_command)
            _command->doCommand();
    }
};

int main()
{

    return 0;
}