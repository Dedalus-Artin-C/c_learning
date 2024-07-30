// file2.cpp
#include <iostream>
#include "h1.hpp"

// 定义全局变量
int shared_var = 42;

int main() {
    printSharedVar(); // 调用 file1.cpp 中的函数
    return 0;
}
