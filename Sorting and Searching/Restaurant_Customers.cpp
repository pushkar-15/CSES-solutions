#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* simulate while maintaining a max count */


int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> events;
    while(n--){
        int inTime, outTime;
        cin >> inTime >> outTime;

        events.push_back({inTime, 1});
        events.push_back({outTime, -1});
    }
    
    sort(events.begin(), events.end());

    int curr = 0, maxCustomers = 0;
    for(auto e : events){
        curr += e.second;
        maxCustomers = max(maxCustomers, curr);
    }

    cout << maxCustomers;
}