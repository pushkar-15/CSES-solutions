#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


void TOH(int n, int s, int e, int m){
    // shifts n disks from source s, to end e, using helper m.

    if(n==1){
        cout << s << " " << e << '\n';
        return;
    }
    TOH(n-1, s, m, e);
    TOH(1, s, e, m);
    TOH(n-1, m, e, s);
}

int main() {
    int n;
    cin >> n;

    cout << (1 << n) - 1 << '\n';
    TOH(n, 1, 3, 2);
}