#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* bruteforce O(sqrt(x)) */


void solve(){
    int x;
    cin >> x;

    int count = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) count += 2;
        if(i*i == x) count--;
    }

    cout << count << endl;
}

int main() {
    int n;
    cin >> n;

    while(n--){
        solve();
    }
}