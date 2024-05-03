#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;

/* recursively add number of nodes by DFS */

int main() {
    int n; 
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for(int v=2; v<=n; v++){
        int u; cin >> u;
        adj[u].push_back(v);
    }

    vector<int> subordinates(n + 1);

    function<void(int)> dfs = [&] (int u){
        for(auto& v : adj[u]){
            dfs(v);
            subordinates[u] += 1 + subordinates[v];
        }
    };

    dfs(1);

    for(int i=1; i<=n; i++) cout << subordinates[i] << ' ';
}