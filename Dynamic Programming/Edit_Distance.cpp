#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int na = a.size(), nb = b.size();

    vector<vector<int>> dp(na+1,vector<int>(nb+1, 1e9)); // dp[i][k] = minimum number of moves to change a[0:i] to b[0:k].
    dp[0][0] = 0;

    for(int i=0; i<=na; i++){
        for(int j=0; j<=nb; j++){
            if(i) dp[i][j] = min(dp[i][j], 1 + dp[i-1][j]); // remove one character from the string a
            if(j) dp[i][j] = min(dp[i][j], 1 + dp[i][j-1]); // add one character to the string a
            if(i && j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1] != b[j-1])); // replace one character in the string a
        }
    }

    cout << dp[na][nb];
}