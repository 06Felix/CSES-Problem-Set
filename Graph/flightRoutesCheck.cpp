#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
#define mod 1000000007
typedef long long ll;
void dfs(ll u, ll pt, vector<vector<ll>>& adj, vector<bool>& vis){
    vis[u] = true;
    for(ll v : adj[u])
        if(!vis[v] and v != pt)
            dfs(v, u, adj, vis);
}
void revDfs(ll u, ll pt, vector<vector<ll>>& revAdj, vector<bool>& revVis){
    revVis[u] = true;
    for(ll v : revAdj[u])
        if(!revVis[v] and v != pt)
            revDfs(v, u, revAdj, revVis);
}
int main() {
    ll n, m, u, v;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    vector<vector<ll>> revAdj(n);
    vector<bool> vis(n, false);
    vector<bool> revVis(n, false);
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }
    dfs(0, -1, adj, vis);
    revDfs(0, -1, revAdj, revVis);
    for(ll i = 0 ; i < n ; i++){
        if(!vis[i]){
            cout << "NO\n1 " << i + 1;
            return 0;
        }
        else if(!revVis[i]){
            cout << "NO\n" << i + 1 << " 1";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
