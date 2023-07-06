// g++ 1-认识线程.cpp -std=c++11 -o a.out -plthread

#include <iostream>
#include <thread>

using namespace std;

void myprint()
{
    cout << "子线程开始" << endl;
    cout << "子线程结束" << endl;
}

int main()
{
    thread thr(myprint); // myprint 为可调用对象
    if (thr.joinable())
        cout << "join正常运行" << endl;
    else
        cout << "join不正常运行" << endl;
    thr.join();
    // thr.detach();
    cout << "主线程开始" << endl;
    cout << "主线程结束" << endl;

    return 0;
}