#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
ll MOD = 1000000007;
using namespace std;
ll find(ll coins[], ll req, ll n){
    vector<ll> dp(req + 1, req + 1);
    dp[0] = 0;
    for(int i = 0 ; i < n ; i++)
        for(int j = coins[i] ; j <= req ; j++)
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
    return dp[req] < req + 1 ? dp[req] : -1;
}
int main() {
    fastio;
    ll n, req;
    cin >> n >> req;
    ll coins[n];
    for(int i = 0; i < n; i++)
        cin >> coins[i];
    cout << find(coins, req, n);
    return 0;
}

