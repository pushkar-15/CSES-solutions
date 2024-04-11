#include <bits/stdc++.h>
using namespace std;

void print(vector<bool>& b, int n){
    for(int i = n; i > 0; i--){
        cout << b[i];
    }
    cout << endl;
}

int main() {
    int n; cin>>n;

    vector<bool> b(16 + 1);
    print(b, n);
    for(int i = 1; i < (1 << n); i++){
        int LSB_idx = __builtin_ffs(i);
        b[LSB_idx] = b[LSB_idx] ^ 1; // keep flipping LSB
        print(b, n);
    }
}