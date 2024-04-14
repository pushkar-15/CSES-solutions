#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;




int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> dp(n, vector<int>(n, 0)); // dp[i][j] = paths from grid[0][0] till grid[i][j].
    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c; cin >> c;
            if(c == '.'){
                if(i-1 >= 0) dp[i][j] += (dp[i-1][j] % MOD);
                if(j-1 >= 0) dp[i][j] += (dp[i][j-1] % MOD);
            }
            else dp[i][j] = 0;
        }
    }

    cout << dp[n-1][n-1] % MOD;
}