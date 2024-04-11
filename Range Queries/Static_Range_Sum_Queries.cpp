#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = (ll) 1e9 + 7;


int main() {
    int n, q; 
    cin >> n >> q;

    vector<ll> x(n + 1);

    // fill x with prefix sums
    for(int i=1; i <= n; i++){
        cin >> x[i];
        x[i] += x[i-1];
    }

    while(q--){
        int a,b; 
        cin >> a >> b;

        cout << x[b] - x[a-1] << endl;
    }
}