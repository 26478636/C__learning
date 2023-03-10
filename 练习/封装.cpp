#include <iostream>

using namespace std;

struct father
{
    int _x;
    father(int x) : _x(x)
    {
        cout << "father默认构造" << endl;
    }
    void print()
    {
        cout << "nihao" << endl;
    }
};

struct child : public father
{
    int _y;
    child(int y) : _y(y)
    {
        cout << "child默认构造" << endl;
    }
};

main()
{
    father f{1};
    child c{2};
    return 0;
}