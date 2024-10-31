#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
#define mod 1000000007
typedef long long ll;
void dfs(ll u, vector<vector<ll>>& adj, vector<bool>& vis, stack<ll>& st){
    vis[u] = true;
    for(ll v : adj[u])
        if(!vis[v])
            dfs(v, adj, vis, st);
    st.push(u);
    
}
void revDfs(ll u, vector<vector<ll>>& revAdj, vector<bool>& revVis, ll curKing, vector<ll>& kingdom){
    revVis[u] = true;
    kingdom[u] = curKing;
    for(ll v : revAdj[u])
        if(!revVis[v])
            revDfs(v, revAdj, revVis, curKing, kingdom);
}
int main() {
    ll n, m, u, v;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    vector<vector<ll>> revAdj(n);
    vector<bool> vis(n, false);
    vector<ll> kingdom(n, 0);
    ll curKing = 0;
    stack<ll> st;
    vector<bool> revVis(n, false);
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }
    for(ll i = 0 ; i < n ; i++)
        if(!vis[i])
            dfs(i, adj, vis, st);
    while(!st.empty()){
        u = st.top();
        st.pop();
        if(!revVis[u]){
            curKing++;
            revDfs(u, revAdj, revVis, curKing, kingdom);
        }
    }
    cout << curKing << "\n";
    for(ll i = 0 ; i < n ; i++)
        cout << kingdom[i] << " ";
    return 0;
}
