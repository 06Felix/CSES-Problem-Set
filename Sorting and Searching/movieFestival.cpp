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
    ll n, st, end;
    cin >> n;
    while(n--){
        cin >> st >> end;
        v.push_back({end, st});
    }
    sort(v.begin(), v.end());
    ll ans = 0, cur = 0;
    for(auto x : v)
        if(x.second >= cur){
            ans++;
            cur = x.first;
        }
    cout << ans;
}

