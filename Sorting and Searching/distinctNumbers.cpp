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
    ll n, a;
    cin >> n;
    set<ll> s;
    for(ll i = 0 ; i < n ; i++){
        cin >> a;
        s.insert(a);
    }
    cout << s.size();
}