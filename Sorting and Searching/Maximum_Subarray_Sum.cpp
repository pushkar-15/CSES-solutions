#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* Kadane's Algorithm */


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& x : a) cin >> x;

    ll maxSoFar = a[0]; // global maximum
    ll maxEndingHere = a[0]; // local maximum

    for(int i=1; i<n; i++){
        maxEndingHere = max(1LL * a[i], maxEndingHere + 1LL * a[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    cout << maxSoFar;
}