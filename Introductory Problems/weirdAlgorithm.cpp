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
    while(n != 1){
        cout << n << " ";
        if((n & 1) == 0)
            n /= 2;
        else
            n = n * 3 + 1;
    }
    cout << 1;
}