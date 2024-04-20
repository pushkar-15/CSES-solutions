#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


int main() {
    int n, m; // n rows, m columns
    cin >> n >> m;

    vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // {U, D, L, R}
    vector<vector<char>> parent(n, vector<char>(m, '#'));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<char> ans(1000000);
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int sr, sc, er, ec;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c; cin >> c;

            if(c=='#') vis[i][j] = 1;
            if(c=='A') sr = i, sc = j;
            if(c=='B') er = i, ec = j;
        }
    }

    queue<pair<int,int>> q;
    q.push({sr, sc});
    vis[sr][sc] = 1;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                vis[nr][nc] = 1;
                q.push({nr, nc});
                dist[nr][nc] = dist[r][c] + 1;

                if(i==0) parent[nr][nc] = 'U';
                if(i==1) parent[nr][nc] = 'D';
                if(i==2) parent[nr][nc] = 'L';
                if(i==3) parent[nr][nc] = 'R';
            }
        }
    }

    if(!vis[er][ec]){
        cout << "NO";
        return 0;
    }

    cout << "YES\n" << dist[er][ec] << '\n';

    int r = er;
    int c = ec;
    for(int i = dist[er][ec]; i > 0; i--){
        ans[i] = parent[r][c];
        if(ans[i] == 'D')  r--;
        if(ans[i] == 'U')  r++;
        if(ans[i] == 'R')  c--;
        if(ans[i] == 'L')  c++;
    }
    for(int i = 1; i <= dist[er][ec]; i++)
        cout << ans[i];
}