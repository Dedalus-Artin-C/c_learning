// file1.cpp
#include <iostream>

// 声明全局变量
extern int shared_var;

void printSharedVar() {
    std::cout << "Shared variable: " << shared_var << std::endl;
}
