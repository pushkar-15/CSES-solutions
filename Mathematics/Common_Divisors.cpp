#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* iterate over all possible GCDs and check if at least 2 of its multiples exist in array */


int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> freq(1e6 + 1);
    for(auto& a : x) cin>>a, freq[a]++;

    for(int i=1e6; i>=0; i--){
        int multiples = 0;
        for(int j=i; j <= 1e6; j += i){
            multiples += freq[j];
            if(multiples >= 2) {cout << i; return 0;}
        }
    }
}