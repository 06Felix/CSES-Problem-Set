#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
#define mod 1000000007
typedef long long ll;
int main() {
    ll n, m, u, v, w;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n);
    vector<ll> dist(n, llm);
    vector<ll> minFlight(n, 0);
    vector<ll> maxFlight(n, 0);
    vector<ll> ways(n, 0);
    dist[0] = 0;
    minFlight[0] = 0;
    maxFlight[0] = 0;
    ways[0] = 1;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
    }
    pq.push({0, 0});
    while(!pq.empty()){
        pair<ll, ll> cur = pq.top();
        pq.pop();
        ll cur_d = cur.first;
        ll u = cur.second;
        if(dist[u] < cur_d)
            continue;
        for(pair<ll, ll> nei : adj[u]){
            ll v = nei.first;
            ll new_d = nei.second;
            if(dist[v] > cur_d + new_d){
                dist[v] = cur_d + new_d;
                minFlight[v] = minFlight[u] + 1;
                maxFlight[v] = maxFlight[u] + 1;
                ways[v] = ways[u];
                pq.push({dist[v], v});
            }
            else if(dist[v] == cur_d + new_d){
                minFlight[v] = min(minFlight[v], minFlight[u] + 1);
                maxFlight[v] = max(maxFlight[v], maxFlight[u] + 1);
                ways[v] += ways[u];
                ways[v] %= mod;
            }
        }
    }
    cout << dist[n - 1] << " " << ways[n - 1] << " " << minFlight[n - 1] << " " << maxFlight[n - 1];
    return 0;
}
