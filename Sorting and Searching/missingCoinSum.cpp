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
    ll ans = 1;
    for(int i = 0 ; i < n && arr[i] <= ans ; i++)
        ans += arr[i];
    cout << ans;
}