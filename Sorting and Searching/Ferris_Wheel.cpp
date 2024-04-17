#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* two pointers */


int main() {
    int n, x;
    cin >> n >> x;

    vector<int> w(n);
    for(auto& k : w) cin >> k;
    sort(w.begin(), w.end());

    int gondolas = 0;
    for(int l = 0, r = n-1; r >= l; r--){
        if(w[l] + w[r] <= x) // fits
            l++;
        gondolas++; // allot in any case
    }

    cout << gondolas;
}