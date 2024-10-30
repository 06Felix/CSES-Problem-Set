#include <bits/stdc++.h>
#define llm LLONG_MAX
typedef long long ll;
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int main() {
    ll n, m, u, v, w;
    cin >> n >> m;
    vector<ll> dist(n, INF);
    vector<vector<ll>> edges(m, vector<ll>(3));
    for(ll i = 0 ; i < m ; i++){
        cin >> u >> v >> w;
        u--;
        v--;
        edges[i] = {u, v, w};
    }
    vector<ll> parent(n, -1);
    dist[0] = 0;
    int lF = -1;
    for(ll i = 0 ; i < n ; i++){
        lF = -1;
        for(ll j = 0 ; j < m ; j++){
            ll x = edges[j][0];
            ll y = edges[j][1];
            ll z = edges[j][2];
            if(dist[x] + z < dist[y]){
                dist[y] = dist[x] + z;
                parent[y] = x;
                lF = y;
            }
        }
        if(lF == -1)
            break;
    }
    if(lF == -1)
        cout << "NO";
    else{
        cout << "YES\n";
        for(ll i = 0 ; i < n ; i++)
            lF = parent[lF];
        ll cur = lF;
        stack<ll> ans;
        while(true){
            ans.push(cur);
            if(cur == lF and ans.size() > 1)
                break;
            cur = parent[cur];
        }
        while(!ans.empty()){
            cout << ans.top() + 1 << " ";
            ans.pop();
        }
    }
}