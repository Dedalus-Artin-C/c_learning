// stack.cpp
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        stack<char> s;
        while (true)
        {
            char ch = cin.get();
            if (ch == '\n' || ch == ' ' || ch == EOF)
            {
                while (!s.empty()){cout << s.top(); s.pop();}
                if (ch == '\n' || ch == EOF) break;
                cout << " ";
            }
            else s.push(ch);

        }
        cout << "\n";

    }
    return 0;
}