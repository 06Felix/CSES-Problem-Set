#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
#define mod 1000000007
typedef long long ll;
class UnionFind{
    public:
        vector<ll> parent;
        vector<ll> size;
        ll cur_max = 0;
        UnionFind(ll n){
            for(ll i = 0 ; i < n ; i++){
                parent.push_back(i);
                size.push_back(1);
            }
        }
        ll find(ll u){
            return u == parent[u] ? u : parent[u] = find(parent[u]);
        }
        bool unionBySize(ll p, ll q){
            ll i = find(p);
            ll j = find(q);
            if(i == j)
                return false;
            if(size[i] > size[j]){
                parent[j] = i;
                size[i] += size[j];
                cur_max = max(cur_max, size[i]);
            }
            else{
                parent[i] = j;
                size[j] += size[i];
                cur_max = max(cur_max, size[j]);
            }
            return true;
        }
};
int main() {
    ll n, m, u, v;
    cin >> n >> m;
    ll parts = n;
    UnionFind uf(n);
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        if(uf.unionBySize(u, v))
            parts--;
        cout << parts << " " << uf.cur_max << "\n";
    }
    return 0;
}
