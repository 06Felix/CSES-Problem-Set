#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
#define llm LLong_MAX;
using namespace std;
ll p10(ll n){
    ll ans = 1;
    for(ll i = 1 ; i <= n ; i++)
        ans *= 10;
    return ans;
}
ll find(ll n){
    if(n < 9)
        return n + 1;
    ll cur_len = 1;
    ll rng = 9 * p10(cur_len - 1) * cur_len;
    while(rng < n){
        n -= rng;
        cur_len++;
        rng = 9 * p10(cur_len - 1) * cur_len;
    }
    string num = to_string(p10(cur_len - 1) + n / cur_len);
    return ll(num[n % cur_len] - '0');
}
ll mod = 1000000007;
int main(){
    fastio;
    ll q, n;
    cin >> q;
    for(ll Q = 0 ; Q < q ; Q++){
        cin >> n;
        cout << find(n - 1) << "\n";
    }
}