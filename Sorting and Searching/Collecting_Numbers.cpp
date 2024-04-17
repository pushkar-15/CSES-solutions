#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* if positions are inverted, increase round-trips */


int main() {
    int n;
    cin >> n;
    
    vector<int> pos(2e5+1);
    for(int i=1; i <= n; i++){
        int num; cin >> num;
        pos[num] = i;
    }

    int rounds = 1;
    for(int i=2; i <= n; i++){
        if(pos[i-1] > pos[i]) rounds++;
    }
    cout << rounds;
}