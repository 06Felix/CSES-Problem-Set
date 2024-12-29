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
    ll n, x;
    cin >> n >> x;
    ll arr[n];
    for(ll i = 0 ; i < n ; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    ll l = 0, r = n - 1;
    ll ans = 0;
    while(l <= r){
        if(arr[r] + arr[l] <= x)
            l++;
        r--;
        ans++;
    }
    cout << ans;
}