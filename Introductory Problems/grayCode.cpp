#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
using namespace std;

ll mod = 1000000007;
ll n;
bool arr[17];
void print(){
    for(ll i = n ; i > 0 ; i--)
        cout << arr[i];
    cout << "\n";
}
int main(){
    fastio;
    cin >> n;
    print();
    for(ll i = 1 ; i < (1 << n) ; i++){
        ll lsb = __builtin_ffs(i);
        arr[lsb] ^= 1;
        print();
    }
}