#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
using namespace std;

ll mod = 1000000007;
int main(){
    fastio;
    ll n;
    cin >> n;
    ll ans = 1;
    ll mul = 2;
    while(n){
        if (n & 1)
            ans = (ans * mul) % mod;
        mul = (mul * mul) % mod;
        n >>= 1;
    }
    cout << ans;
}