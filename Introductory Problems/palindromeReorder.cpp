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
    string str;
    ll ct[26] = {0};
    cin >> str;
    ll n = str.length();
    for(ll i = 0 ; i < n ; i++)
        ct[str[i] - 'A']++;
    ll odd = -1;
    for(ll i = 0 ; i < 26 ; i++){
        if(ct[i] & 1){
            if(odd != -1){
                cout << "NO SOLUTION";
                return 0;
            }
            else
                odd = i;
        }
    }
    for(ll i = 0 ; i < 26 ; i++)
        for(ll j = 0 ; j < ct[i] / 2 ; j++)
            cout << char(i + 'A');
    if(odd != -1)
        cout << char(odd + 'A');
    for(ll i = 25 ; i >= 0 ; i--)
        for(ll j = 0 ; j < ct[i] / 2 ; j++)
            cout << char(i + 'A');
}