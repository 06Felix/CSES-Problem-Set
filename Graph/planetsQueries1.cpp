#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
#define mod 1000000007
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
int main() {
    fastio;
    ll n, m, cur, k;
    cin >> n >> m;
    int dp[n + 1][31];
    for(ll i = 1 ; i <= n ; i++)
        cin >> dp[i][0];
    for(ll i = 1 ; i < 30 ; i++)
        for(ll j = 1 ; j <= n ; j++)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
    for(ll i = 0 ; i < m ; i++){
        cin >> cur >> k;
        for(ll j = 0 ; j < 30 and k > 0 ; j++)
            if(k & (1ll << j)){
                cur = dp[cur][j];
                k -= (1ll << j);
            }
        cout << cur << "\n";
    }
    return 0;
}
