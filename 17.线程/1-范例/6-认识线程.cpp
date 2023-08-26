#include <iostream>
#include <thread>

using namespace std;

void print(unique_ptr<int> uni)
{
    cout << "子线程创建" << endl;
}

int main()
{
    // 智能指针
    unique_ptr<int> uni(new int(100));
    thread thr(print, move(uni));
    thr.join();

    cout << "主线程结束" << endl;
    return 0;
}