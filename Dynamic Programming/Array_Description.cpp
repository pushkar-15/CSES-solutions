#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n,vector<int>(m+1,0)); // dp[i][v] == number of ways to fill the array up to index i, if x[i] = v

    int x0; cin >> x0;
    if(x0 == 0) fill(dp[0].begin(), dp[0].end(), 1);
    else dp[0][x0] = 1;

    for(int i=1; i<n; i++){
        int x; cin >> x;
        if(x == 0){
            for(int v=1; v<=m; v++){
                for (int k : {v-1,v,v+1}) {
                    if (k >= 1 && k <= m) (dp[i][v] += dp[i-1][k]) %= MOD;
                }
            }
        }
        else{
            for (int k : {x-1,x,x+1}) {
                if (k >= 1 && k <= m) (dp[i][x] += dp[i-1][k]) %= MOD;
            }
        }
    }

    int ans = 0;
    for (int v = 1; v <= m; v++) (ans += dp[n-1][v]) %= MOD;
    cout << ans << endl;
}