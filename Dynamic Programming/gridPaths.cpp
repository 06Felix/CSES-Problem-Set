#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
const ll MOD = 1e9+7;
 
 
int main(){
    fastio;
    ll n;
    cin >> n;
    char ch;
    vector<ll> dp(n, 0);
    dp[0] = 1;
    for(ll i = 0 ; i < n ; i++)
        for(int j = 0; j < n; j++){
            cin >> ch;
            if(ch == '*')
                dp[j] = 0;
            else if(j > 0)
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    cout << dp[n - 1];
}
