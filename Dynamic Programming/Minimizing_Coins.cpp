#include <bits/stdc++.h>
using namespace std;

#define ll long long

/* iterate on all possibilities 
    dp[i - coin] is a subproblem for dp[i]
*/

int main() {
    int n, x; 
    cin >> n >> x;

    vector<int> coins(n);
    for(auto& coin : coins)
        cin >> coin;

    vector<int> dp(x + 1, 1e9); // dp[k] = minimum number of coins required for sum = k
    dp[0] = 0;
    
    for (int i = 1; i <= x; i++) {
        for(auto& coin : coins) {
            if(coin <= i)
                dp[i] = min(dp[i], 1 + dp[i-coin]);
        }
    }

    cout <<(dp[x] < 1e9 ? dp[x] : -1 )<< '\n';
}