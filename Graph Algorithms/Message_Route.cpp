#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* BFS on grid while keeping track of path using prev array */


int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> prev(n+1,0); // stores path

    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int cur = q.front(); q.pop();
        if (cur==n){
            break;
        }
        for (int child : graph[cur]){
            if (!prev[child]){
                prev[child] = cur;
                q.push(child);
            }
        }
    }
    if(!prev[n]){ // still unvisited
        cout << "IMPOSSIBLE";
    }
    else{ // generate path from prev array
        vector<int> path;
        path.push_back(n);

        int end = prev[n];
        while(end != 1){
            path.push_back(end);
            end = prev[end];
        }
        path.push_back(end);

        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for(int c : path) cout << c << " ";
    }
}