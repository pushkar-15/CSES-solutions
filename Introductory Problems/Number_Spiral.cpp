#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll r, c; cin >> r >> c;
    if (r > c) {
        if (r % 2) {
            cout << (r - 1) * (r - 1) + c << "\n";
        } else {
            cout << r * r - c + 1 << "\n";
        }
    } else {
        if (c % 2) {
            cout << c * c - r + 1 << "\n";
        } else {
            cout << (c - 1) * (c - 1) + r << "\n";
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}