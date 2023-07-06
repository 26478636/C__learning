#include <iostream>
#include <thread>

using namespace std;

int main()
{
    cout << "主线程开始" << endl;
    auto _lambda = []
    {
        cout << "lambda1" << endl;
        cout << "lambda2" << endl;
        cout << "lambda3" << endl;
        cout << "lambda4" << endl;
    };

    thread thr(_lambda);
    thr.join();
    cout << "主线程结束" << endl;
    return 0;
}