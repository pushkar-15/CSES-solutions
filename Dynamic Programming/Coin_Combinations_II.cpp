#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;

/* 
    Once coins[i] is skipped, we cannot ever go back to take coins[i].
    Hence, order is maintained.
*/


int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(auto& coin : coins) cin>>coin;
    
    // dp[i][k] is answer for sum = k and all coins from i to n-1 being usable.
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for(int i=0; i<n; i++) 
        dp[i][0] = 1; // only 1 way to make sum = 0.

    for(int i = n-1; i >= 0; i--){
        for(int sum = 1; sum <= x; sum++){
            int skipping = dp[i + 1][sum]; // skip coins[i]

            int picking = 0;
            if(sum - coins[i] >= 0){
                picking = dp[i][sum - coins[i]]; // pick coins[i]
            }

            dp[i][sum] = (skipping + picking) % MOD;
        }
    }
    
    cout << dp[0][x] << endl;
}