g++重要编译参数

// -g 告诉GCC产生能被GNU调试器GDB使用的调试信息，以调试程序
g++ -g text.cpp -o text

// -O[n] 优化源代码
eg: g++ -O2 text.cpp

// -l 指定库文件 -L 指定库文件路径
// -l 在 /lib 和 /user/lib 和 /user/local/lib 里的库直接用-l参数就能链接
// 链接glog库
g++ -lglog text.cpp
// 如果库文件没放在上面三个目录里，则用-L
g++ -L/home/bing/mytextlibfolder -lmytexr text.cpp

// -I 指定头文件搜索目录
// 如果头文件不在/user/include 需要gcc找不到，这是需要用-I
g++ -I/myinclude text.cpp

// -Wall 打印出gcc提供的警告信息
g++ -Wall text.cpp

// -w 关闭警告信息
g++ -w text.cpp

// -std=c++11 设置编译标准
g++ -std=c++11 text.cpp

// -o 指定输出文件名 链接那里有说

// -D 定义宏
// -DDEBUG 定义DEBUG宏
g++ -DDEBUG text.cpp 