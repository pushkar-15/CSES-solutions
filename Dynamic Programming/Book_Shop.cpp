#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* classic Knapsack */


int main() {
    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    for(int i=0; i<n; i++) cin >> price[i];
    vector<int> pages(n);
    for(int i=0; i<n; i++) cin >> pages[i];
    
    // dp[k] is answer for total money = k.
    vector<int> dp(x+1);

    for(int i=0; i<n; i++){
        for(int j=x; j>=price[i]; j--){
            int take = dp[j - price[i]] + pages[i]; // take ith book
            int notTake = dp[j]; // skip ith book
            
            dp[j] = max(take, notTake);
        }
    }

    cout << dp[x];
}