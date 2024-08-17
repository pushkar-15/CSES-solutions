#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

/*
    0-1 Knapsack:
    dp[i][sum] = dp[i-1][sum] + dp[i-1][sum-i]
*/

int main() {
    int n; cin >> n;

    int target = n * (n + 1) / 2;
    if(target % 2 != 0){ // impossible case
        cout << 0;
        return 0;
    }

    target /= 2;
    
    vector<vector<int>> dp(n, vector<int>(target+1, 0)); // dp[i][s] == ways to make sum s with numbers in [1 to i]
    dp[0][0] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<=target; j++){
            dp[i][j] = (dp[i][j] + dp[i-1][j] + ((j-i >= 0) ? dp[i-1][j-i] : 0)) % MOD;
        }
    }

    cout << dp[n-1][target];
}