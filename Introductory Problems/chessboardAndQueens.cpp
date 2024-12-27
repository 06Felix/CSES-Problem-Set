#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
#define llm LLong_MAX;
using namespace std;

ll mod = 1000000007;
bool res[8][8];
bool col[8];
bool d1[15];
bool d2[15];
ll ans = 0;
void find(ll i){
    if(i == 8){
        ans++;
        return;
    }
    for(ll j = 0 ; j < 8 ; j++){
        if(!res[i][j] and !col[j] and !d1[i + j] and !d2[j - i + 8 - 1]){
            col[j] = d1[i + j] = d2[j - i + 8 - 1] = true;
            find(i + 1);
            col[j] = d1[i + j] = d2[j - i + 8 - 1] = false;
        }
    }
}
int main(){
    fastio;
    char ch;
    for(ll i = 0 ; i < 8 ; i++)
        for(ll j = 0 ; j < 8 ; j++){
            cin >> ch;
            res[i][j] = (ch == '*');
        }
    find(0);
    cout << ans;
    return 0;
}