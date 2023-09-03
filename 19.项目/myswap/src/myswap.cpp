#include "../include/myswap.h"

void myswap::run()
{
    int temp;
    temp = _a;
    _a = _b;
    _b = temp;
}

void myswap::printInfo()
{
    std::cout << "_a: " << _a << std::endl;
    std::cout << "_b: " << _b << std::endl;
}