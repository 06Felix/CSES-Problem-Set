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
    ll arr[n];
    for(int i = 0 ; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    ll mid = arr[n / 2];
    ll ans = 0;
    for(int i = 0 ; i < n ; i++)
        ans += abs(mid - arr[i]);
    cout << ans;
}