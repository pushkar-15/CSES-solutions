#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int xum = 0;
    ll n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        ll x;
        cin >> x;
        xum ^= x;
    }
    for (int i = 1; i <= n; i++)
    {
        xum ^= i;
    }
    cout << xum;
}