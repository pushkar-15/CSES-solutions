#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
    a - 1x - 2y = 0     and     b - 2x - 1y = 0.
    hence 2a - b = 3y   and     2b - a = 3x.
    hence a + b = 3(x + y).
*/

void solve(){
    ll a, b;
    cin >> a >> b;

    if((2*a-b) >= 0 && (2*b-a) >= 0 && (a + b) % 3 == 0)
        cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while(t--){
        solve();
    }
}