#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
using namespace std;

ll MOD = 1000000007;
const int mx = 1e6;
ll ans[mx + 1];
void find(){
    for(int d = 1 ; d <= mx ; d++)
        for(int num = d ; num <= mx ; num += d)
            ans[num]++;
}
int main(){
    fastio;
    find();
    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << ans[n] << "\n";
    }
}