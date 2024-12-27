#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
using namespace std;

ll mod = 1000000007;
char str[9];
int main(){
    fastio;
    char ch;
    ll i = 0;
    while(cin >> ch)
        str[i++] = ch;
    sort(str, str + i);
    set<string> ans;
    ans.insert(str);
    while(next_permutation(str, str + i))
        ans.insert(string(str, str + i));
    cout << ans.size() << "\n";
    for(string x : ans)
        cout << x << "\n";
}