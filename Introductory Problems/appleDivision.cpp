#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
#define llm LLong_MAX;
using namespace std;

ll mod = 1000000007;
ll find(ll i, ll n, ll arr[], ll s1, ll s2){
    if(i == n)
        return abs(s1 - s2);
    return min(find(i + 1, n, arr, s1 + arr[i], s2), find(i + 1, n, arr, s1, s2 + arr[i]));
}
int main(){
    fastio;
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i = 0 ; i < n ; i++)
        cin >> arr[i];
    cout << find(0LL, n, arr, 0LL, 0LL);
}