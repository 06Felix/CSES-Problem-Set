#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
typedef long long ll;
void dfs(ll u, ll pt, vector<bool>& vis, vector<vector<ll>>& adj){
    vis[u] = true;
    for(ll v : adj[u])
        if(!vis[v])
            dfs(v, u, vis, adj);
}
int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    vector<ll> degree(n, 0);
    vector<ll> level(n, -1);
    vector<ll> parent(n, -1);
    vector<bool> vis(n, false);
    vector<ll> ans(n);
    queue<ll> q;
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        degree[v]++;
    }
    dfs(0, -1, vis, adj);
    if(!vis[n - 1]){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    level[0] = 0;
    
    for(ll i = 0 ; i < n ; i++)
        if(degree[i] == 0){
            q.push(i);
        }
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(ll j : adj[cur]){
            if(level[cur] != -1 and level[j] < level[cur] + 1){
                level[j] = level[cur] + 1;
                parent[j] = cur;
            }
            if(--degree[j] == 0)
                q.push(j);
        }
    }
    ll size = level[n - 1] - level[0];
    cout << size + 1 << "\n";
    for(ll i = size, u = n - 1 ; i >= 0 ; i--){
        ans[i] = u + 1;
        u = parent[u];
    }
    for(ll i = 0 ; i <= size ; i++)
        cout << ans[i] << " ";
    return 0;
}
