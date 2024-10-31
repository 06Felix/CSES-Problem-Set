#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
typedef long long ll;
int main(){
    ll n, m, k, u, v, w;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> arr(n);
    vector<ll> count(n);
    for(int i = 0 ; i < m ; i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        arr[u].push_back({v, w});
    }
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        vector<ll> cur = pq.top();
        pq.pop();
        ll cur_d = cur[0];
        ll u = cur[1];
        count[u]++;
        if(u == n - 1){
            cout<<cur_d<<" ";
            if(count[u] == k)
                return 0;
        }
        if(count[u] <= k){
            for(pair<ll, ll> nei : arr[u]){
                ll v = nei.first;
                ll new_d = nei.second;
                pq.push({cur_d + new_d, v});
            }
        }
    }
}