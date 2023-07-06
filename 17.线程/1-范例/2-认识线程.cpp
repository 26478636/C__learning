#include <iostream>
#include <thread>

using namespace std;

class Point
{
public:
    int &a; // 成员属性
    // 有参构造
    Point(int &_a) : a(_a)
    {
        cout << "有参构造" << endl;
    }
    // 拷贝构造
    Point(const Point &_point) : a(_point.a)
    {
        cout << "拷贝构造" << endl;
    }
    // 析构函数
    ~Point()
    {
        cout << "析构函数" << endl;
    }
    // 操作符重载小括号，使Point对象，成为可调用对象
    void operator()()
    {
        cout << "子线程开始" << endl;
        cout << "子线程结束" << endl;
    }
};

int main()
{
    cout << "主程序开始" << endl;
    int a = 7;
    Point point(a);
    thread thr(point);
    thr.join();
    cout << "主程序结束" << endl;
    return 0;
}