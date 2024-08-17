#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> x(n);
    for(auto& c : x) cin >> c;

    int max_sum = 1000 * n;
    vector<vector<bool>> dp(n + 1, vector<bool>(max_sum + 1, false)); // dp[i][s] == true if making a sum of s is possible by using the first i coins
    dp[0][0] = true;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=max_sum; j++){
            dp[i][j] = dp[i-1][j]; // check if making this sum without this coin is possiblie or not
            int remaining = j - x[i-1]; // if making remaining sum without this coin is possiblie, then making this sum is also possible
            if(remaining >= 0 && dp[i-1][remaining]) dp[i][j] = true;
        }
    }

    vector<int> possible;
    for (int j = 1; j <= max_sum; j++) if (dp[n][j]) possible.push_back(j);

    cout << possible.size() << endl;
    for (int v : possible) cout << v << ' ';
}