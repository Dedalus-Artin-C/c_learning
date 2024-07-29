#include <iostream>
#include <coordin.hpp>
using namespace std;

int main()
{
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y) // read into rect structure
    {
        pplace = rect_to_polar(rplace); // convert to polar coordinates
        show_polar(pplace); // display results
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Bye!\n";
    return 0;
}