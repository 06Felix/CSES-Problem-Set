#include <iostream>
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
    if(n == 1)
        cout << 1;
    else if(n <= 3)
        cout << "NO SOLUTION";
    else{
        for(ll i = 2 ; i <= n ; i += 2)
            cout << i << " ";
        for(ll i = 1 ; i <= n ; i += 2)
            cout << i << " ";
    }
}