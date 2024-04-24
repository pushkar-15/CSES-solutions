#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* two pointers: sliding window */


int main() {
    int n;
    cin >> n;
    
    vector<int> songs(n);
    for(auto& s : songs) cin >> s;

    int ans = 0;
    multiset<int> ms;
    
    for(int l=0, r=0; l<n && r<n; r++){
        while(ms.count(songs[r])){
            ms.erase(ms.find(songs[l]));
            l++;
        }
        ms.insert(songs[r]); // re-insert current instance
        ans = max(ans, r - l + 1);
    }

    cout << ans;
}