#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
#define llm LLong_MAX;
using namespace std;

ll mod = 1000000007;
int main(){
    fastio;
    ll n, m, q, p;
    multiset<ll> st;
    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++){
        cin >> p;
        st.insert(-p);
    }
    for(ll i = 0 ; i < m ; i++){
        cin >> q;
        auto id = st.lower_bound(-q);
        if(id == st.end())
            cout << -1;
        else{
            cout << -(*id);
            st.erase(id);
        }
        cout << "\n";
    }
}