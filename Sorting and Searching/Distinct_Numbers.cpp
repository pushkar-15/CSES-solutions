#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;



int main() {
    int n;
    cin >> n;

    map<int,int> freq; // unordered_map gives TLE
    int distinctCount = 0;

    for(int i=0; i<n; i++){
        int x; cin >> x;

        if(freq[x] == 0) freq[x]++, distinctCount++;
    }

    cout << distinctCount;
}