#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n; cin >> n;
    vector<int> x(n);
    ll sum = 0;
    for(auto& num : x) cin >> num, sum += num*1LL;

    //  dp[l][r] == score1−score2 while considering the game played only on interval [l, r]
    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for(int l = n-1; l >= 0; l--) {
        for(int r = l; r < n; r++) {
            if (l == r) dp[l][r] = x[l]; // player1 picks the only element present in the interval
            else dp[l][r] = max(
                        x[l] - dp[l+1][r], // player1 picks x[l] then it is player2's turn on [l+1, r] (negative because it is player2's turn)
                        x[r] - dp[l][r-1]); // player1 picks x[r] then it is player2's turn on [l, r-1]
        }
    }

    cout << (sum + dp[0][n-1]) / 2 << '\n';
}