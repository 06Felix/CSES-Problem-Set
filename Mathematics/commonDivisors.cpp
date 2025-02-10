#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
using namespace std;

ll MOD = 1000000007;
const int mx = 1e6;
ll divisor[mx + 1];
int main(){
    fastio;
    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        divisor[n]++;
    }
    for(int i = mx ; i >= 1 ; i--){
        int ct = 0;
        for(int j = i ; j <= mx ; j += i)
            ct += divisor[j];
        if(ct >= 2){
            cout << i;
            return 0;
        }
    }
}