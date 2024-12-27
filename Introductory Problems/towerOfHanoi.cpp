#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
using namespace std;

ll mod = 1000000007;
void move(ll from, ll to, ll depth){
    if(depth == 1){
        cout << from << " " << to << "\n";
        return;
    }
    ll other = 6 - from - to;
    move(from, other, depth - 1);
    cout << from << " " << to << "\n";
    move(other, to, depth - 1);
}
int main(){
    fastio;
    ll n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    move(1LL, 3LL, n);
}