#include <bits/stdc++.h>
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
    ll sum = n * (n + 1) / 2;
    if(sum & 1){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    sum /= 2;
    vector<ll> s1, s2;
    for(ll i = n ; i >= 1 ; i--){
        if(sum - i >= 0){
            sum -= i;
            s1.push_back(i);
        }
        else
            s2.push_back(i);
    }
    cout << s1.size() << "\n";
    for(ll x : s1)
        cout << x << " ";
    cout << "\n" << s2.size() << "\n";
    for(ll x : s2)
        cout << x << " ";
}