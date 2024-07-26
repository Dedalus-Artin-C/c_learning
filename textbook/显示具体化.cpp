#include <iostream>
using namespace std;

template <typename T>
void Swap(T &a,T &b);

struct job{
    char name[20];
    double salary;
    int floor;
};

template <> void Swap<job>(job &a,job &b);