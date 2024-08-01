// external.cpp -- external variables
#include <iostream>
using namespace std;

double warming = 0.3 ;// external defined

// function prototypes
void update(double dt);
void local();

int main()
{
    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);
    cout << "Global warming is " << warming << " degrees.\n";
    local();
    cout << "Global warming is " << warming << " degrees.\n";
    return 0;

}