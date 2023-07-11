#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// 创建类 不希望被外部访问
class Point
{
private:
    // 不希望被外部访问
    Point() {}
    ~Point() {}
    // 创建两个静态成员属性
    static Point *_point;
    static mutex _mutex;

public:
    // 创建静态成员方法
    static Point *get()
    {
        if (_point == nullptr)
        {
            // 上锁 防止外部的访问
            _mutex.lock();
            if (_point == nullptr)
            {
                _point = new Point();
            }
            // 解锁
            _mutex.unlock();
        }
        return _point;
    }
};

// 初始化
Point *Point::_point = nullptr;
mutex Point::_mutex;

void print()
{
    cout << Point::get() << endl;
}

int main()
{
    // 创建多线程
    thread th1(&print);
    thread th2(&print);
    thread th3(&print);

    th1.join();
    th2.join();
    th3.join();

    return 0;
}