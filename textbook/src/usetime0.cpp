// usetime0.cpp --using the first draft of the Time class
// compile usetime0.cpp and mytime0.cpp together

#include <iostream>
#include <mytime0.hpp>

using namespace std;
int main()
{
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;
    Time total1;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding.Sum(fixing);
    cout << "coding.Sum() = ";
    total.Show();
    cout  << endl;

    total1 = coding + fixing;
    cout << "coding + fixing = ";
    total1.Show();
    cout << endl;

    return 0;
}
