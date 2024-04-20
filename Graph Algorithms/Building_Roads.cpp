#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* 
    While DFS, store one node from each component (representative node).
    Then build roads by joining these stored nodes adjacently.
*/


void dfs(vector<vector<int>> &adj, vector<int> &vis, int node){
    vis[node]=1;

    for(auto child : adj[node]){
        if(!vis[child]){
            dfs(adj, vis, child);
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1);
    int components = 0;
    vector<int> roads;

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(adj, vis, i);
            components++;
            roads.push_back(i);
        }
    }

    cout << components-1 << endl;
    for(int i=0; i < roads.size() - 1; i++){
        cout << roads[i] << " " << roads[i+1] << endl;
    }
}