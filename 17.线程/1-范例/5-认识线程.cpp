#include <iostream>
#include <thread>

using namespace std;

// 创建类
class A
{
public:
    int a;
    // 有参构造
    // 又称类型转变函数
    A(int _a) : a(_a)
    {
        cout << "有参构造成功" << endl;
    }
    // 拷贝构造
    A(const A &B) : a(B.a)
    {
        cout << "拷贝构造成功" << endl;
    }
    // 析构函数
    ~A()
    {
        cout << "析构函数" << endl;
    }
};

// 构建函数
void print(const int a, const A &AA)
{
    cout << std::this_thread::get_id() << endl;
    cout << "子线程创建成功" << endl;
}

int main()
{
    cout << "主线程开始" << endl;
    int a = 1;
    int b = 1;
    thread thr(print, a, A(b));
    thr.join();
    cout << "主线程结束" << endl;
    return 0;
}