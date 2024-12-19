#include <iostream>
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
    ll arr[n];
    ll ans = 0;
    if(n > 0)
        cin >> arr[0];
    for(ll i = 1 ; i < n ; i++){
        cin >> arr[i];
        if(arr[i] < arr[i - 1]){
            ans += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }
    cout << ans;
}