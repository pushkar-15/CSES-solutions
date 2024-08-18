#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

int n = 1e6; // maximum n possible
ll dp[(int)1e6][2];

void precompute(){
    /*
        dp[i][linked] == ways till ith level if the tiles at ith level are linked.
        linked == 1 means only 1 tile (of width 2) is present at ith level
        linked == 0 means two seperate tiles (of width 1 each) are present at ith level
    */

    dp[0][0] = 1;
    dp[0][1] = 1;

    // BOTTOM UP:
    for(int i=1; i<n; i++){
        ll terminateBoth = dp[i-1][0] % mod;
        ll terminateLinked = dp[i-1][1];
        ll extendBoth = dp[i-1][0];
        ll extendOne = (2 * dp[i-1][0]) % mod;
        ll extendLinked = dp[i-1][1];

        dp[i][0] = (terminateBoth + terminateLinked + extendBoth + extendOne) % mod;
        dp[i][1] = (terminateBoth + terminateLinked + extendLinked) % mod;
    }
    // cout << (dp[n-1][1] + dp[n-1][0]) % mod << '\n'; // ans for n
}

int main() {
    precompute();
    int t; cin>>t;
    while(t--){
        int ni; cin>>ni; // current n
        cout << (dp[ni-1][1] + dp[ni-1][0]) % mod << '\n';
    }
}