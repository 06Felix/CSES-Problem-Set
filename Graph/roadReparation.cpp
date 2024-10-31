#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
#define mod 1000000007
typedef long long ll;
class UnionFind{
    public:
        vector<ll> parent;
        vector<ll> rank;
        UnionFind(ll n){
            for(ll i = 0 ; i < n ; i++){
                parent.push_back(i);
                rank.push_back(0);
            }
        }
        ll find(ll u){
            return u == parent[u] ? u : parent[u] = find(parent[u]);
        }
        bool unionByRank(ll p, ll q){
            ll i = find(p);
            ll j = find(q);
            if(i == j)
                return false;
            if(rank[i] < rank[j])
                parent[i] = j;
            else if(rank[j] < rank[i])
                parent[j] = i;
            else{
                parent[i] = j;
                rank[j]++;
            }
            return true;
        }
};
int main() {
    ll n, m, u, v, w;
    ll ans = 0, edges = 0;
    cin >> n >> m;
    UnionFind uf(n);
    vector<vector<pair<ll, ll>>> adj(n);
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        pq.push({w, u, v});
    }
    while(!pq.empty()){
        vector<ll> cur = pq.top();
        pq.pop();
        w = cur[0];
        u = cur[1];
        v = cur[2];
        if(uf.unionByRank(u, v)){
            edges++;
            ans += w;
        }
    }
    if(edges == n - 1)
        cout << ans;
    else
        cout << "IMPOSSIBLE";
    return 0;
}
