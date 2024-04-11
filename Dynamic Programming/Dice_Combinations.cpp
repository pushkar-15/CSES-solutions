#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = (ll) 1e9 + 7;


int main() {
    int n; 
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, 6); j++) {
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }

    cout << dp[n] << "\n";
}