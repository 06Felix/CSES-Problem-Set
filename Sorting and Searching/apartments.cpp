#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
ll MOD = 1000000007;
using namespace std;
int main() {
    fastio;
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n], b[m];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    for(int i = 0 ; i < m ; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int aplt = 0, apt = 0, ans = 0;
    while(aplt < n){
        while(apt < m and b[apt] < a[aplt] - k)
            apt++;
        if(apt < m and a[aplt] >= b[apt] - k and b[apt] + k >= a[aplt]){
            apt++;
            aplt++;
            ans++;
        }
        else
            aplt++;
    }
    cout << ans;
}

