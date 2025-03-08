#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
const int maxX = 1e6;
const ll MOD = 1e9+7;
 
 
int main(){
    fastio;
    ll n, m;
    cin >> n;
    ll ans = 0;
    while(n){
        ans++;
        m = n;
        ll mx = 0;
        while(n){
            mx = max(mx, n % 10);
            n /= 10;
        }
        n = m - mx;
    }
    cout << ans << "\n";
    
}
