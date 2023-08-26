#include <iostream>
#include <thread>
#include <string>

using namespace std;

// 第一个参数最好不是用引用类型
// 第二个参数使用引用类型
void print(const int i, const string &s)
{
    cout << "子线程开始" << i << endl; // 这里尽管使用引用，但是线程内部发生的其实是值传递
    cout << "子线程结束" << s.c_str() << endl;
}

int main()
{
    cout << "主线程开始" << endl;
    int a = 1;
    char s[] = "ni hao!";
    // 不使用，数组的首地址类型，而是将其转化成string类型

    // 深思 s 什么时候被构造成string类型的 有没有可能主线程结束，string类型还没有被构造成功
    // 深思 string(s)类型 是在主线程被创建的 所以后续的事情不用担心了

    // thread thr(print, a, s);         // 可调用对象 参数1 参数2
    // 在子线程构造
    thread thr(print, a, string(s)); // 可调用对象 参数1 参数2
    // 在主线程构造
    thr.join();

    cout << "主线程结束" << endl;
    return 0;
}