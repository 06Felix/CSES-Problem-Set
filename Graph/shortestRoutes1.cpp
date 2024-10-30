#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;

void dijkstra(vector<vector<pair<ll, ll>>>& adj, ll n) {
    vector<ll> dist(n, LLONG_MAX);
    dist[0] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if(d > dist[u])
            continue;
        for (auto& edge : adj[u]) {
            ll v = edge.first;
            ll weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    for (ll i = 0; i < n; i++)
        cout << dist[i] << " ";
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
    }
    dijkstra(adj, n);
    return 0;
}
