#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* if (prefix sum + 1) is impossible to make, it is the answer */


int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for(auto& x : coins) cin >> x;

    sort(coins.begin(), coins.end());

    int pref = 0;
    for(auto& coin : coins){
        if(coin > pref + 1) break;
        pref += coin;
    }

    cout << pref + 1;
}