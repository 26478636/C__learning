#include <iostream>

using namespace std;

class Strategy
{
public:
    // 想要实现的功能--排序功能
    virtual void sort(int arr[], int size) = 0;
};

// 想要Strategy实现的具体功能
class context
{
private:
    int *arr;
    int size;
    Strategy *strategy;

public:
    // 设置参数
    void setData(int *_arr, int _size)
    {
        arr = _arr;
        size = _size;
    }
    // 设置策略
    void setStrategy(Strategy *_stratagy)
    {
        strategy = _stratagy;
    }
    // 实现的功能，然后调用函数
    void sort()
    {
        if (strategy && arr)
        {
            cout << "排序开始" << endl;
            strategy->sort(arr, size);
        }
    }
    // 打印输出
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// 实现具体功能
class Bubble : public Strategy
{
public:
    void sort(int *arr, int size)
    {
        cout << "冒泡排序开始" << endl;
        if (size <= 1)
            return;
        for (int i = 1; i < size; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
                else
                    break;
            }
        }
    }
};

class Insertsort : public Strategy
{
public:
    void sort(int *arr, int size)
    {
        cout << "插入排序开始" << endl;
        if (size <= 1)
            return;
        for (int i = 0; i < size - 1; i++)
        {
            int mid = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[mid])
                    mid = j;
            }
            int temp = arr[i];
            arr[i] = arr[mid];
            arr[mid] = temp;
        }
    }
};

int main()
{
    context *cont = new context();
    int arr[] = {1, 4, 5, 2, 5, 6, 86, 54, 65};
    cont->setData(arr, sizeof(arr) / sizeof(int));
    Bubble *bubble = new Bubble();
    Insertsort *insertsort = new Insertsort();
    cont->setStrategy(bubble);
    cont->sort();
    cont->print();
    delete insertsort;
    delete bubble;
    delete cont;
    return 0;
}