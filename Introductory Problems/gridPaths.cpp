#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
#define llm LLong_MAX;
using namespace std;
char dirs[48];
bool vis[8][8];
ll ans = 0;
bool check(ll i, ll j){
    return i >= 1 and j >= 1 and i < 8 and j < 8 and !vis[i][j];
}
void dfs(ll i, ll j, ll ct){
    if(ct == 48 || (i == 7 and j == 1)){
        ans += (ct == 48 and i == 7 and j == 1);
        return;
    }
    if(check(i + 1, j) and check(i - 1, j) and !check(i, j - 1) and !check(i, j + 1))
        return;
    if(check(i, j - 1) and check(i, j + 1) and !check(i + 1, j) and !check(i - 1, j))
        return;
    vis[i][j] = true;
    if(dirs[ct] == 'U' || dirs[ct] == '?')
        if(check(i - 1, j))
            dfs(i - 1, j, ct + 1);
    if(dirs[ct] == 'D' || dirs[ct] == '?')
        if(check(i + 1, j))
            dfs(i + 1, j, ct + 1);
    if(dirs[ct] == 'L' || dirs[ct] == '?')
        if(check(i, j - 1))
            dfs(i, j - 1, ct + 1);
    if(dirs[ct] == 'R' || dirs[ct] == '?')
        if(check(i, j + 1))
            dfs(i, j + 1, ct + 1);
    vis[i][j] = false;
}
ll mod = 1000000007;
int main(){
    fastio;
    char ch;
    for(ll i = 0 ; i < 48 ; i++)
        cin >> dirs[i];
    dfs(1, 1, 0);
    cout << ans;
}