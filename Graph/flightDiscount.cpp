#include <bits/stdc++.h>
#define llm LLONG_MAX
typedef long long ll;
using namespace std;
int main() {
    ll n, m, u, v, w;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> arr(n);
    for(ll i = 0 ; i < m ; i++){
        cin >> u >> v >> w;
        u--;
        v--;
        arr[u].push_back({v, w});
    }
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    vector<vector<ll>> dist(n, vector<ll>(2, llm));
    dist[0][0] = 0;
    dist[0][1] = 0;
    pq.push({0, 0, 1});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        ll cur_d = cur[0];
        ll u = cur[1];
        ll avail = cur[2];
        if(dist[u][avail] < cur_d)
            continue;
        for(auto &pr : arr[u]){
            ll v = pr.first;
            ll new_d = pr.second;
            if(avail){
                if(dist[v][1] > cur_d + new_d){
                    dist[v][1] = cur_d + new_d;
                    pq.push({dist[v][1], v, 1});
                }
                if(dist[v][0] > cur_d + (new_d / 2)){
                    dist[v][0] = cur_d + (new_d / 2);
                    pq.push({dist[v][0], v, 0});
                }
            }
            else{
                if(dist[v][0] > cur_d + new_d){
                    dist[v][0] = cur_d + new_d;
                    pq.push({dist[v][0], v, 0});
                }
            }
        }
    }
    cout<<dist[n - 1][0];
}