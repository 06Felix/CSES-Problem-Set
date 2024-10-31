#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ll n, q, l ,r;
    cin >> n >> q;
    ll prf[n + 1];
    prf[0] = 0;
    for(ll i = 1 ; i <= n ; i++){
        cin >> prf[i];
        prf[i] += prf[i - 1];
    }
    while(q-- > 0){
        cin >> l >> r;
        cout << prf[r] - prf[l - 1] << "\n"; 
    }
}