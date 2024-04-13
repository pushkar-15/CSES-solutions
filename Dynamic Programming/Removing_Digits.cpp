#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1, 1e9);
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        string num = to_string(i);

        for(auto& c : num){ // try all digits in the number
            int lastDigit = c - '0';

            if(lastDigit != 0){
                dp[i] = min(dp[i], dp[i - lastDigit] + 1);
            }
        }
    }

    cout << dp[n] << endl;
}