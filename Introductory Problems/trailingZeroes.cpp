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
    ll ans = 0;
    while(n){
        n /= 5;
        ans += n;
    }
    cout << ans;
}