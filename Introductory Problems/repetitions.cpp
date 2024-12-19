#include <iostream>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
using namespace std;
int main(){
    fastio;
    string str;
    cin >> str;
    ll ans = 1;
    ll cur = 1;
    for(ll i = 1 ; i < str.length() ; i++){
        if(str[i - 1] == str[i])
            cur++;
        else
            cur = 1;
        ans = max(ans, cur);
    }
    cout << ans;
}