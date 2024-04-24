#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;

/* if prefixSum - target is already seen then subarray us found */

int main() {
    int n, x; 
    cin >> n >> x;

    map<ll,int> freq;
    freq[0]++;
    ll ans = 0, curr = 0;

    while (n--) {
        int i; cin >> i;
        curr += i; // prefix sum
        ans += freq[curr - x];
        freq[curr]++;
    }
    
    cout << ans << "\n";
}