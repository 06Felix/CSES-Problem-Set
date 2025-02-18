#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
ll MOD = 1000000007;
using namespace std;
ll find(int n){
    int mx = max(8, n + 1);
    ll dp[mx] = {0};
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    for(int i = 7 ; i <= n ; i++){
        dp[i] += dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6];
        dp[i] %= MOD;
    }
    return dp[n];
}
int main() {
    fastio;
    int n;
    cin >> n;
    cout << find(n);
    return 0;
}

