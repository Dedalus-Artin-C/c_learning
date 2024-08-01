//support.cpp --use external variable

#include <iostream>
extern double warming;
using namespace std;

void update(double dt);
void local();

using std::cout;
void update(double dt){
    extern double warming;
    warming += dt;
    cout << "Updating global warming to " << warming << " degrees.\n";
}

void local(){
    double warming = 0.8;
    cout << "Local warming = " << warming << " degrees.\n";
    cout << "But global warming = " << ::warming << " degrees.\n";
}