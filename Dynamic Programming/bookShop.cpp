#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;

int main() {
    fastio;
    ll n, x;
    cin >> n >> x;
    vector<ll> price(n), pages(n);
    for (ll i = 0; i < n; i++)
        cin >> price[i];
    for (ll i = 0; i < n; i++)
        cin >> pages[i];
    vector<ll> dp(x + 1, 0);
    for (ll i = 0; i < n; i++)
        for (ll j = x; j >= price[i]; j--)
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
    cout << dp[x] << "\n";
}
