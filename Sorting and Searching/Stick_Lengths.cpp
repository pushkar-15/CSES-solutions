#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* make all sticks equal to median length */


int main() {
    int n;
    cin >> n;

    vector<ll> sticks(n);
    for(auto& x : sticks) cin >> x;
    sort(sticks.begin(), sticks.end());

    ll medianLength = sticks[n/2];

    ll minCost = 0;
    for(auto& stick : sticks)
        minCost += abs(stick - medianLength);
    
    cout << minCost;
}