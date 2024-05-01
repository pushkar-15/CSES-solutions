#include <bits/stdc++.h>
using namespace std;


/* 
    check if graph is bipartite by coloring adjacent nodes with opposite colors.
    if adjacent node is already visited and wrongly colored, graph is not bipartite. 
*/


int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> col(n, -1);
    bool isPossible = true;

    auto bfs = [&](int s) {
        col[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (col[v] == -1) {
                    col[v] = !col[u]; // color adjacent node with opposite color.
                    q.push(v);
                } else if (col[v] == col[u]) {
                    isPossible = false;
                    return;
                }
            }
        }
    };

    for (int i = 0; i < n; i++) {
        if (col[i] == -1) bfs(i);
    }

    if(!isPossible) cout << "IMPOSSIBLE\n";
    else for (int x : col) cout << x + 1 << " ";
}