#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;

/* 
    Two Sum approach 
    Maintain a hashmap to check for existing complement
*/

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> a(n);
    map<int,int> mp;

    for(int i=0; i<n; i++){
        cin >> a[i];
        int complement = target - a[i];

        if(mp.find(complement) != mp.end()){
            cout << i + 1 << " " << mp[complement] + 1;
            return 0;
        }

        mp[a[i]] = i;
    }

    cout << "IMPOSSIBLE";
}