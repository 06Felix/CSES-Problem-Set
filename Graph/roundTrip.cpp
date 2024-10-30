#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

bool dfs(ll u, vector<vector<ll>>& adj, vector<int>& color, vector<ll>& parent, stack<ll>& ans) {
    color[u] = 1;
    for (ll v : adj[u]){
        if(v == parent[u])
            continue;
        if (color[v] == 0) {
            parent[v] = u;
            if (dfs(v, adj, color, parent, ans))
                return true;
        }
        else if (color[v] == 1) {
            ans.push(v);
            for (ll x = u ; x != v; x = parent[x])
                ans.push(x);
            ans.push(v);
            return true;
        }
    }
    color[u] = 2;
    return false;
}

void findCycle(vector<vector<ll>>& adj, ll n) {
    vector<int> color(n, 0);
    vector<ll> parent(n, -1);
    stack<ll> ans;
    for (ll u = 0; u < n; ++u)
        if (color[u] == 0)
            if (dfs(u, adj, color, parent, ans))
                break;
    if(!ans.empty()){
        cout<<ans.size()<<"\n";
        while (!ans.empty()) {
            cout << ans.top() + 1 << " ";
            ans.pop();
        }
    }
    else
        cout<<"IMPOSSIBLE";
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    findCycle(adj, n);
    return 0;
}
