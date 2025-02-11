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
    ll n, k, a;
    cin >> n >> k;
    for(ll i = 1 ; i <= n ; i++){
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    while(l < r){
        ll sum = v[l].first + v[r].first;
        if(sum == k){
            cout << v[l].second << " " << v[r].second;
            return 0;
        }
        if(sum < k)
            l++;
        else
            r--;
    }
    cout << "IMPOSSIBLE";
}

