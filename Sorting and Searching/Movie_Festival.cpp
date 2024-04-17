#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* sort by end time, and count number of non overlapping intervals */


int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> movies;
    for(int i=0; i<n; i++){
        int startTime, endTime;
        cin >> startTime >> endTime;

        movies.push_back({endTime, startTime});
    }
    
    sort(movies.begin(), movies.end());

    int ans = 0, previousEndTime = -1;
    for(int i=0; i<n; i++){
        if(previousEndTime <= movies[i].second){
            previousEndTime = movies[i].first;
            ans++;
        }
    }

    cout << ans;
}