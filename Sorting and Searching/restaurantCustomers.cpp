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
    map<ll, ll> m;
    ll n;
    cin >> n;
    while (n-- > 0) {
        ll a, b;
        cin >> a >> b;
        m[a] += 1;
        m[b + 1] -= 1;
    }
    ll ans = 0, cur = 0;
    for (auto& pair : m) {
        cur += pair.second;
        ans = max(cur, ans);
    }
    cout << ans;
    return 0;
}

