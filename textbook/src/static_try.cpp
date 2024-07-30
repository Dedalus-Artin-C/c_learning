#include <iostream>

class MyClass {
public:
    static int count; // 静态成员变量

    MyClass() {
        count++; // 每次创建对象时，计数器加一
    }

    static void printCount() { // 静态成员函数
        std::cout << "Count: " << count << std::endl;
    }
};

int MyClass::count = 0; // 静态成员变量初始化

int main() {
    MyClass obj1;
    MyClass obj2;

    MyClass::printCount(); // 调用静态成员函数
    obj1.printCount(); // 通过对象调用静态成员函数
    obj2.printCount(); // 通过对象调用静态成员函数
    MyClass::count = 10; // 直接修改静态成员变量
    MyClass::printCount(); // 再次调用静态成员函数
    std::cout << "Count: " << MyClass::count << std::endl; // 直接访问静态成员变量
    
    return 0;
}
