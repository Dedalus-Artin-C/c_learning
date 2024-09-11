// stone.cpp -- user-defined conversions

#include "stonewt.hpp"
#include <iostream>

using namespace std;

void display(const Stonewt &st, int n);

int main()
{
    Stonewt incongnition = 275;
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);

    cout << "The celebrity weighed ";
    incongnition.show_stn();
    cout << "The detective weighed ";
    wolfe.show_stn();
    cout << "The President weighed ";
    taft.show_stn();
    incongnition = 276.8; //uses constructor for conversion
    taft = 325; // same as taft = Stonewt(325);
    cout << "After dinner, the celebrity weighed ";
    incongnition.show_stn();
    cout << "After dinner, the President weighed ";
    taft.show_stn();
    display(taft, 2);
    cout << "The wrestler weighed even more.\n";
    display(422, 2);
    cout << "No stone left unturned\n";
    return 0;

}

void display(const Stonewt &st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow!" ;
        st.show_stn();
    }
}