#include "./include/myswap.h"

int main()
{
    myswap _myswap(10, 20);
    _myswap.printInfo();
    _myswap.run();
    std::cout << "----------------------------" << std::endl;
    _myswap.printInfo();
    return 0;
}