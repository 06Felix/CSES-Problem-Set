#include <iostream>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
using namespace std;
int main(){
    fastio;
    ll n, a;
    cin >> n;
    ll sum = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        cin >> a;
        sum += a;
    }
    cout << n * (n + 1) / 2 - sum;
}