#ifndef UTIL_H
#define UTIL_H
#include <iostream>

// ref to https://blog.csdn.net/qq_35280514/article/details/51637920
// 用来终止递归并打印最后一个元素的函数
// 此函数必须在可变参数版本的print定义之前声明
template <typename T>
void print(const T &t)
{
    std::cout << t << std::endl;  // 参数包中最后一个元素
}
// 包中除最后一个元素之外的其他元素都会调用这个版本的pirnt
template <typename T, typename... Args>
void print(const T &t, const Args &... rest)
{
    std::cout << t << ", ";  // 打印第一个实参, 包中元素减1
    print(rest...);  // 递归调用, 打印剩余实参, ...表示展开rest参数包
}

#endif /* ifndef UTIL_H */
