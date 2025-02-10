#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
using namespace std;

ll mod = 1000000007;
map<pair<ll, ll>, int> mem;
ll find(ll n, ll k){
    if(mem[{n, k}])
        return mem[{n, k}];
    if(n == 1)
        return mem[{n, k}] = 1;
    if(k <= (n + 1) / 2){
        if(2 * k > n)
            return mem[{n, k}] = 1;
        return 2 * k;
    }
    ll rem = find(n / 2, k - (n + 1) / 2);
    if(n & 1)
        return mem[{n, k}] = 2 * rem + 1;
    return mem[{n, k}] = 2 * rem - 1;
}
int main(){
    fastio;
    ll t, n, q;
    cin >> t;
    while(t--){
        cin >> n >> q;
        cout << find(n, q) << "\n";
    }
}