#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;
typedef long long ll;

vector<vector<ll>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<char> dir = {'R', 'D', 'L', 'U'};
stack<char> ans;
ll x = -1, y = -1;
void backtrack(vector<vector<char>>& arr, vector<vector<char>>& path, ll i, ll j){
    if(arr[i][j] == 'A')
        return;
    char ch = path[i][j];
    ans.push(ch);
    if(ch == 'U')
        backtrack(arr, path, i + 1, j);
    else if(ch == 'D')
        backtrack(arr, path, i - 1, j);
    else if(ch == 'L')
        backtrack(arr, path, i, j + 1);
    else if(ch == 'R')
        backtrack(arr, path, i, j - 1);
}
bool dfs(vector<vector<char>>& arr, vector<vector<ll>>& count, ll i, ll j, ll n, ll m, ll cur_ct, vector<vector<char>>& path){
    if(i == 0 or j == 0 or i == n - 1 or j == m - 1){
        backtrack(arr, path, i, j);
        return true;
    }
    ll t = count[i][j];
    count[i][j] = -1;
    for(ll dr = 0; dr < 4; ++dr){
        ll n_x = i + dirs[dr][0];
        ll n_y = j + dirs[dr][1];
        if(n_x < 0 || n_y < 0 || n_x >= n || n_y >= m || count[n_x][n_y] <= cur_ct + 1 || arr[n_x][n_y] == '#')
            continue;
        path[n_x][n_y] = dir[dr];
        if(dfs(arr, count, n_x, n_y, n, m, cur_ct + 1, path))
            return true;
    }
    count[i][j] = t;
    return false;
}

void find(vector<vector<char>>& arr, vector<vector<ll>>& mon, ll n, ll m) {
    vector<vector<ll>> count(n, vector<ll>(m, INT_MAX));
    vector<vector<char>> path(n, vector<char>(m, '\0'));
    queue<vector<ll>> q;
    for(const auto& mn : mon) {
        q.push(mn);
        count[mn[0]][mn[1]] = 0;
    }
    while(!q.empty()) {
        vector<ll> cur = q.front();
        q.pop();
        ll cur_x = cur[0];
        ll cur_y = cur[1];
        ll cur_ct = cur[2];

        for(ll dr = 0; dr < 4; ++dr) {
            ll n_x = cur_x + dirs[dr][0];
            ll n_y = cur_y + dirs[dr][1];
            if(n_x < 0 || n_y < 0 || n_x >= n || n_y >= m || count[n_x][n_y] != INT_MAX || arr[n_x][n_y] == '#')
                continue;
            count[n_x][n_y] = cur_ct + 1;
            q.push({n_x, n_y, count[n_x][n_y]});
        }
    }
    if(dfs(arr, count, x, y, n, m, 0, path)){
        cout<<"YES\n"<<ans.size()<<"\n";
        while(!ans.empty()){
            cout<<ans.top();
            ans.pop();
        }
    }
    else
        cout<<"NO";
}

int main() {
    ll n, m;
    cin >> n >> m;
    
    char a;
    vector<vector<char>> arr(n, vector<char>(m));
    vector<vector<ll>> mon;
    for (ll i = 0; i < n; ++i)
        for(ll j = 0; j < m; ++j) {
            cin >> a;
            arr[i][j] = a;
            if(a == 'M')
                mon.push_back({i, j, 0});
            else if(a == 'A') {
                x = i;
                y = j;
            }
        }
    find(arr, mon, n, m);
    return 0;
}
