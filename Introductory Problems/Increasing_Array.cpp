#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        ll mx = max(x[i], x[i - 1]);
        ans += mx - x[i];
        x[i] = mx;
    }
    cout << ans;
}