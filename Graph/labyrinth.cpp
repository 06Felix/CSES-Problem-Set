#include <bits/stdc++.h>
using namespace std;
stack<char> ans;
void find(vector<vector<char>>& path, int i, int j){
    char c = path[i][j];
    if(c == 'A')
        return;
    ans.push(c);
    if(c == 'U')
        find(path, i + 1, j);
    else if(c == 'D')
        find(path, i - 1, j);
    else if(c == 'R')
        find(path, i, j - 1);
    else
        find(path, i, j + 1);
}
void bfs(vector<vector<char>>& arr, int i, int j, int n, int m) {
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<char>> path(n, vector<char>(m, 'X'));
    int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    char dir[4] = {'R', 'D', 'U', 'L'};
    path[i][j] = 'A';
    vis[i][j] = true;
    q.push({i, j});
    while(!q.empty()){
        pair<int, int> cur = q.front();
        i = cur.first;
        j = cur.second;
        if(arr[i][j] == 'B'){
            cout<<"YES\n";
            find(path, i, j);
            cout<<ans.size()<<"\n";
            while(!ans.empty()){
                cout<<ans.top();
                ans.pop();
            }
            return;
        }
        q.pop();
        for(int dr = 0 ; dr < 4 ; dr++){
            int new_x = i + dirs[dr][0];
            int new_y = j + dirs[dr][1];
            if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m || vis[new_x][new_y] || arr[new_x][new_y] == '#')
                continue;
            vis[new_x][new_y] = true;
            path[new_x][new_y] = dir[dr];
            q.push({new_x, new_y});
        }
    }
    cout<<"NO";
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    char a;
    int x_st = -1, y_st = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            arr[i][j] = a;
            if (arr[i][j] == 'A') {
                x_st = i;
                y_st = j;
            }
        }
    }
    bfs(arr, x_st, y_st, n, m);
    return 0;
}
