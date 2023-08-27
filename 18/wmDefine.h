#ifndef _WM_HEADER_H_
#define _WM_HEADER_H_
// 一些宏定义

#include <cstdio>

// 打印日志
#define WMBLOG(fmt, ...)            \
    do                              \
    {                               \
        printf(fmt, ##__VA_ARGS__); \
    } while (0)

#define NS_WM_BEGIN \
    namespace wm    \
    {

#define NS_WM_END }

// 使用该命名空间
#define USING_NS_WM using namespace wm

#endif