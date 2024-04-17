#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* two pointers */


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for(auto& x : a) cin >> x;
    for(auto& x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int allottedCount = 0;
    for(int i=0, j=0; i<n && j<m;){
        if(b[j] < a[i] - k) j++;
        else if(b[j] > a[i] + k) i++;
        else {i++; j++; allottedCount++;}
    }

    cout << allottedCount;
}