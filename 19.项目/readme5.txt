如何编译运行

// 直接编译
// 将*.cpp编译成可执行文件，这里自动生成a.out
g++ *.cpp -Ihead
./a.out

// 增加参数编译，并运行
g++ *.cpp -Ihead -std=c++11 -Wall -O2 -o main
./main