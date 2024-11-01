#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
int main(){
    fastio;
    char ch;
    ll n, m, x1, x2, y1, y2;
    cin >> n >> m;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for(ll i = 1 ; i <= n ; i++)
        for(ll j = 1 ; j <= n ; j++){
            dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            cin >> ch;
            if(ch == '*')
                dp[i][j]++;
        }
    for(ll i = 0 ; i < m ; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << "\n";
    }
}