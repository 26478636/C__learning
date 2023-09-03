#ifndef _WM_SWAP_H_
#define _WM_SWAP_H_

#include <iostream>

class myswap
{
private:
    int _a;
    int _b;

public:
    myswap(int a, int b) : _a(a), _b(b)
    {
    }
    void run();
    void printInfo();
};

#endif
