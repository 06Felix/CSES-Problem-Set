#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
ll MOD = 1000000007;
using namespace std;
int main() {
    fastio;
    vector<pair<ll, ll>> v;
    ll n, a, cur = 0, ans = INT_MIN;
    cin >> n;
    for(ll i = 1 ; i <= n ; i++){
        cin >> a;
        cur = max(cur + a, a);
        ans = max(ans, cur);
    }
    cout << ans;
}

