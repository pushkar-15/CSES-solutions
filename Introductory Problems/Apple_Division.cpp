#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* take or not-take each apple using bitmasking and update ans */


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& x : a) cin >> x;

    ll diff = LLONG_MAX;

    for(int mask = 0; mask < (1 << n); mask++){
        ll group_1 = 0, group_2 = 0;
        for(int i=0; i<n; i++){
            if(mask & (1 << i)){
                group_1 += a[i];
            }
            else {
                group_2 += a[i];
            }
        }
        diff = min(diff, abs(group_1 - group_2));
    }
    cout << diff;
}