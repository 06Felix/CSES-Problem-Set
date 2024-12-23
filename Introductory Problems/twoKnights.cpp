#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
using namespace std;

int main(){
    fastio;
    ll n;
    cin >> n;
    for(ll k = 1 ; k <= n ; k++){
        ll total = (k * k) * (k * k - 1) / 2;
        ll wrong = 4 * (k - 2) * (k - 1);
        cout << total - wrong << "\n";
    }
}