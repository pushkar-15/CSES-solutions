#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1;

vector<int> adj[MAXN];
int dist[MAXN];

void dfs(int node, int parent) {
    for (int neighbor : adj[node]) {
        if (neighbor != parent) { // if (node is not leaf)
            dist[neighbor] = dist[node] + 1;
            dfs(neighbor, node);
        }
    }
}

int main() {
    int n; 
    cin >> n;

    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // First DFS to find the farthest node from node 1
    dist[1] = 0;
    dfs(1, -1);

    // Find the node that is farthest from node 1
    int farthest_node = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > dist[farthest_node]) {
            farthest_node = i;
        }
    }

    // Second DFS from the farthest node found
    dist[farthest_node] = 0;
    dfs(farthest_node, -1);

    // Find the maximum distance which is the diameter of the tree
    int diameter = 0;
    for (int i = 1; i <= n; i++) {
        diameter = max(diameter, dist[i]);
    }

    cout << diameter << endl;
}