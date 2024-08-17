#include <bits/stdc++.h>
using namespace std;

/* Iterate on all positions of making a cut and add results of the two parts after cutting */

int main() {
    int w,h; cin>>w>>h;

    vector<vector<int>> dp(w+1,vector<int>(h+1, 1e9)); // dp[i][j] == minimum number of moves to convert an i*j rectangle to all squares

    for(int i=0; i<=w; i++){
        for(int j=0; j<=h; j++){
            if(i==j) dp[i][j] = 0;
            else{
                for(int k=1; k<i; k++) dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
                for(int k=1; k<j; k++) dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
            }
        }
    }

    cout << dp[w][h] << endl;
}