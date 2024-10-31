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
ll neg(ll n, ll i){
    return 2 * n - i + 1;
}
int main() {
    ll n, m, a, b;
    char a1, b1;
    cin >> m >> n;
    vector<vector<ll>> adj(2 * n + 1);
    vector<vector<ll>> revAdj(2 * n + 1);
    vector<bool> vis(2 * n + 1, false);
    vector<ll> kingdom(2 * n + 1, 0);
    vector<bool> revVis(2 * n + 1, false);
    vector<char> ans(n + 1);
    ll curKing = 0;
    stack<ll> st;
    for (ll i = 0; i < m; ++i) {
        cin >> a1 >> a >> b1 >> b;
        if(a1 == '-')
            a = neg(n, a);
        if(b1 == '-')
            b = neg(n, b);
        adj[neg(n, a)].push_back(b);
        adj[neg(n, b)].push_back(a);
        revAdj[a].push_back(neg(n, b));
        revAdj[b].push_back(neg(n, a));
    }
    for(ll i = 1 ; i <= 2 * n ; i++)
        if(!vis[i])
            dfs(i, adj, vis, st);
    while(!st.empty()){
        ll u = st.top();
        st.pop();
        if(!revVis[u]){
            curKing++;
            revDfs(u, revAdj, revVis, curKing, kingdom);
        }
    }
    for(ll i = 1 ; i <= n ; i++){
        if(kingdom[i] == kingdom[neg(n, i)]){
            cout << "IMPOSSIBLE";
            return 0; 
        }
        ans[i] = (kingdom[i] > kingdom[neg(n, i)]) ? '+' : '-';
    }
    for(ll i = 1 ; i <= n ; i++)
        cout << ans[i] << " ";
    return 0;
}
