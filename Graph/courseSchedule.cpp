#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
typedef long long ll;
int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    vector<ll> degree(n, 0);
    vector<ll> ans;
    queue<ll> q;
    ll size = 0;
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        degree[v]++;
    }
    for(ll i = 0 ; i < n ; i++)
        if(degree[i] == 0){
            ans.push_back(i + 1);
            q.push(i);
            size++;
        }
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(ll j : adj[cur]){
            if(--degree[j] == 0){
                ans.push_back(j + 1);
                size++;
                q.push(j);
            }
        }
    }
    if(size == n)
        for(ll path : ans)
            cout<<path<<" ";
    else
        cout<<"IMPOSSIBLE";
    return 0;
}
