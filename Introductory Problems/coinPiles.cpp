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
    ll t, x, y;
    cin >> t;
    for(ll T = 0 ; T < t ; T++){
        cin >> x >> y;
        if((x + y) % 3 != 0 or x > 2 * y or y > 2 * x)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}