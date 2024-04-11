#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = (ll) 1e9 + 7;

/* compute a^b using Binary Exponentiation Algorithm*/
ll binpow(ll a, ll x) {
    ll res = 1;
    while (x > 0) {
        if (x & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}

void solve(){
    ll a, b;
    cin >> a >> b;
    cout << binpow(a, b) << endl;
}

int main() {
    ll n; 
    cin >> n;

    while(n--){
        solve();
    }
}