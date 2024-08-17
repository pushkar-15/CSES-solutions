#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> dp;

    for(int i=0; i<n; i++){
        int x; cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if(it == dp.end()) dp.push_back(x); // append x
        else *it = x; // replace by x
    }

    cout << dp.size();
}