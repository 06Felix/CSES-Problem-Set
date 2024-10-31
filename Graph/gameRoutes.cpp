#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
typedef long long ll;
int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    vector<ll> degree(n, 0);
    vector<ll> dp(n, 0);
    queue<ll> q;
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        degree[v]++;
    }
    dp[0] = 1;
    
    for(ll i = 0 ; i < n ; i++)
        if(degree[i] == 0)
            q.push(i);
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(ll j : adj[cur]){
            dp[j] = (dp[j] + dp[cur]) % 1000000007; 
            if(--degree[j] == 0)
                q.push(j);
        }
    }
    cout << dp[n - 1];
    return 0;
}
