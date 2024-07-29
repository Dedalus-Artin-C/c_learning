#include <iostream>
using namespace std;

template <typename T>
void Swap(T &a, T &b);

struct job
{
    char name[20];
    double salary;
    int floor;
};

template <>
void Swap<job>(job &j1, job &j2);
void Show(job &j);

int main()
{
    cout.precision(2);
    cout.setf(std::ios_base::fixed, ios::floatfield); // 用定点记法生成浮点类型区别于scientific不会产生e
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << endl;
    cout << "Using compiler-generated int swapper: ";
    Swap(i, j); // generate int version of Swap()
    cout << "Now i, j = " << i << ", " << j << endl
         << endl;
    job sue = {"Susan Yaffee", 73000.60, 7};     // sue's info
    job sidney = {"Sidney Taffee", 78060.72, 9}; // sidney's info
    cout << "Before job swapping: " << endl;
    Show(sue);
    cout << endl;
    Show(sidney);
    cout << endl;
    Swap(sue, sidney); // swap sue's and sidney's info
    cout << "After job swapping: " << endl;
    Show(sue);
    cout << endl;
    Show(sidney);
    cout << endl;
    Show(sue);
    Show(sidney);
    cin.get();
    return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <>
void Swap<job>(job &j1, job &j2)
{
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
    // job结构体中只有salary和floor是可交换的，name不可交换
}

void Show(job &j)
{
    cout  << j.name << ": " << j.salary << " on floor " << j.floor << endl;
}


// template <class T>
// void Swap(T &a, T &b);

// template <> void Swap<job>(job &a, job &b); // 特化job类型的Swap()函数
// int main(void)
// {
//     template void Swap<char>(char &, char &); // 非特化int类型的Swap()函数
//     short a, b;
// }