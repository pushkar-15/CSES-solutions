#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = (ll) 1e9 + 7;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)


int main() {
    fastio;
    
    // no. of multiples of k in range [1...n] = floor(n / k)

    int n; cin >> n;
    ll ans = 0;
    for (ll i = 5; i <= n; i *= 5) {
        ans += n / i;
    }
    cout << ans << "\n";
}