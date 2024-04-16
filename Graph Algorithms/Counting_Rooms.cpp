#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;

int n,m;


/* count number of disjoint components */


void dfs(vector<vector<bool>>& graph, int i, int j){
    graph[i][j] = 0;

    if(i+1 < n && graph[i+1][j]) dfs(graph, i+1,j);
    if(i-1 >= 0 && graph[i-1][j]) dfs(graph, i-1,j);
    if(j+1 < m && graph[i][j+1]) dfs(graph, i,j+1);
    if(j-1 >= 0 && graph[i][j-1]) dfs(graph, i,j-1);

    return;
}


int main() {
    cin >> n >> m;

    vector<vector<bool>> graph(n, vector<bool>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c; cin >> c;

            graph[i][j] = ((c=='.') ? 1 : 0);
        }
    }

    int components = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]) dfs(graph, i,j), components++;
        }
    }

    cout << components;

}