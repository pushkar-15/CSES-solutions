#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    for (ll k = 1; k <= n; k++)
    {
        ll totalPositions = (k * k) * (k * k - 1) / 2; // (k^2)C2
        ll positionsUnderAttack = 4LL * (k - 1) * (k - 2); // 2 * (no. of 3*2 and 2*3 rectangles in k*k square)
        cout << totalPositions - positionsUnderAttack << endl;
    }
}