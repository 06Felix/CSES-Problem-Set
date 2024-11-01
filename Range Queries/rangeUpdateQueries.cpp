#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
#define mod 1000000007
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
class FWT{
    public:
        ll n;
        vector<ll> sums;
        FWT(ll n) : n(n + 1), sums(n + 1) {}
        void update(ll i, ll del){
            while(i < n){
                sums[i] += del;
                i += (i & -i);
            }
        }
        ll getSum(ll i){
            ll ans = 0;
            while(i > 0){
                ans += sums[i];
                i -= (i & -i);
            }
            return ans;
        }
        
};
int main(){
    fastio;
    ll n, m, a, b, u, k, ch;
    cin >> n >> m;
    ll arr[n + 1];
    FWT ft(n);
    for(ll i = 1 ; i <= n ; i++){
        cin >> arr[i];
        ft.update(i, arr[i]);
        ft.update(i + 1, -arr[i]);
    }
    for(int i = 0 ; i < m ; i++){
        cin >> ch;
        if(ch == 1){
            cin >> a >> b >> u;
            ft.update(a, u);
            ft.update(b + 1, -u);
        }
        else{
            cin >> k;
            cout << ft.getSum(k) << "\n";
        }
    }
}