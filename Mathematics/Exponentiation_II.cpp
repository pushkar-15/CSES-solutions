#include <bits/stdc++.h>
using namespace std;

#define ll long long


/*
    According the Fermat's Little Theorem:
    A^(p - 1) ≣ 1 (mod p) if p is a prime.

    So if we rewrite B^C as q*(p - 1) + r, 
    then A^B^C  = A ^ (q*(p - 1) + r)
                = A ^ (x*(M - 1)) * A^y.

    From Fermat's little theorem, we know A ^ x*(M-1) ≣ 1 (mod M).
    So, A^B^C ≣ A^y (mod M).

    From B^C = x * (M - 1) + y,
    y = B^C % (M-1).
*/


/* Binary Exponentiation Algorithm*/
ll binpow(ll a, ll x, ll MOD) {
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
    const ll MOD = (ll) 1e9 + 7;
    ll a, b, c;
    cin >> a >> b >> c;

    cout << binpow(a, binpow(b, c, MOD - 1), MOD) << endl;
}

int main() {
    ll n; 
    cin >> n;

    while(n--){
        solve();
    }
}