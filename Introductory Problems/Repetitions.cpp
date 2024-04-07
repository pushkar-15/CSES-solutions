#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mx = 1;
    int count = 1;

    char c;
    cin >> c;
    char d;
    while (cin >> d)
    {
        if (c == d)
        {
            count++;
        }
        else
        {
            count = 1;
        }

        mx = max(count, mx);
        c = d;
    }
    cout << mx;
}