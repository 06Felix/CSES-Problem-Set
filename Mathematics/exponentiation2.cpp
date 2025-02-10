#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
using namespace std;

ll MOD = 1000000007;
map<pair<ll, ll>, int> mem;
ll power(ll a, ll b, ll mod) {
        ll res = 1;
        while (b > 0) {
            if ((b & 1) == 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
int main(){
    fastio;
    ll t, a, b, c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        cout << power(a, power(b, c, MOD - 1), MOD) << "\n";
    }
}