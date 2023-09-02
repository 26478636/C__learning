#ifndef _WM_DEFINE_H_
#define _WM_DEFINE_H_
// 一些宏定义

#include <stdio.h>

// 打印日志
#define WMBLOG(fmt, ...)            \
    do                              \
    {                               \
        printf(fmt, ##__VA_ARGS__); \
    } while (0)

#define CREATE(__TYPE__)                 \
    static __TYPE__ *create()            \
    {                                    \
        __TYPE__ *node = new __TYPE__(); \
        if (node && node->init())        \
        {                                \
            node->autorelease();         \
            return node;                 \
        }                                \
        else                             \
        {                                \
            delete node;                 \
            node = nullptr;              \
        }                                \
        return nullptr;                  \
    }

#define NS_WM_BEGIN \
    namespace wm    \
    {

#define NS_WM_END }

// 使用该命名空间
#define USING_NS_WM using namespace wm

#endif