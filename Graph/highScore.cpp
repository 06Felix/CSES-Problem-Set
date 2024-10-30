#include <bits/stdc++.h>
#define llm LLONG_MAX
typedef long long ll;
using namespace std;

void dfs(ll i, vector<bool>& vis, vector<vector<ll>>& adj) {
    vis[i] = true;
    for(ll j : adj[i])
        if(!vis[j])
            dfs(j, vis, adj);
}

void rDfs(ll i, vector<bool>& rVis, vector<vector<ll>>& revAdj) {
    rVis[i] = true;
    for(ll j : revAdj[i])
        if(!rVis[j])
            rDfs(j, rVis, revAdj);
}

int main() {
    ll n, m, u, v, w;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    vector<vector<ll>> revAdj(n);
    vector<ll> dist(n, llm);
    vector<vector<ll>> edges(m, vector<ll>(3));
    for(ll i = 0 ; i < m ; i++){
        cin >> u >> v >> w;
        u--;
        v--;
        edges[i] = {u, v, -w};
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }
    vector<bool> vis(n, false);
    vector<bool> rVis(n, false);
    dfs(0, vis, adj);
    rDfs(n - 1, rVis, revAdj);
    bool imp = true;
    dist[0] = 0;
    for(ll i = 0 ; i < n && imp ; i++){
        imp = false;
        for(ll j = 0 ; j < m ; j++){
            ll x = edges[j][0];
            ll y = edges[j][1];
            ll z = edges[j][2];
            if(dist[x] != llm and dist[x] + z < dist[y]){
                dist[y] = dist[x] + z;
                imp = true;
                if(i == n - 1 && vis[y] && rVis[y]){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << -dist[n - 1];
}