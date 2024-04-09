#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = (ll) 1e9 + 7;

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

int main() {
    ll n; 
    cin >> n;

    /* compute 2^n using Binary Exponentiation Algorithm*/
    cout << binpow(2LL, n);
}