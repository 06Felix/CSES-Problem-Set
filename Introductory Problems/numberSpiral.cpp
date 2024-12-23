#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
using namespace std;

int main(){
    fastio;
    ll x, y, t;
    cin >> t;
    for(ll T = 0 ; T < t ; T++){
        cin >> x >> y;
        ll mx = max(x, y) - 1;
        if(mx & 1){
            if(x < y)
                cout << mx * mx + x;
            else
                cout << mx * mx + 2 * mx + 2 - y;
        }
        else{
            if(x < y)
                cout << mx * mx + 2 * mx + 2 - x;
            else
                cout << mx * mx + y;
        }
        
        cout << "\n";
    }
    
}