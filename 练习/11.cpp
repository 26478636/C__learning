#include <iostream>

using namespace std;

long long func(int n)
{
    if (n == 1)
        return 1;
    if (n % 2 == 0)
    {
        return func(n / 2) + 1;
    }
    else
    {
        return func(3 * n + 1) + 1;
    }
}

int main()
{
    int ans = 1;
    for (int i = 2; i < 100; i++)
    {
        if (func(i) > func(ans))
        {
            ans = i;
        }
    }
    cout << ans << endl;
    cout << func(ans) << endl;
    return 0;
}