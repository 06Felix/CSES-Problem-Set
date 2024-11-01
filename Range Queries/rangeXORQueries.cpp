#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
#define mod 1000000007
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
int main(){
    fastio;
    ll n, m, l ,r;
    cin >> n >> m;
    ll prf[n + 1];
    prf[0] = 0;
    for(ll i = 1 ; i <= n ; i++){
        cin >> prf[i];
        prf[i] ^= prf[i - 1];
    }
    for(int i = 0 ; i < m ; i++){
        cin >> l >> r;
        cout << (prf[r] ^ prf[l - 1]) << "\n";
    }
}