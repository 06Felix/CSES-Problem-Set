#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;

class FenwickTree {
    vector<ll> tree;
    ll n;
public:
    FenwickTree(ll n) : n(n + 1), tree(n + 1, 0) {}
    
    void update(ll i, ll value) {
        for ( ; i < n ; i += i & -i)
            tree[i] += value;
    }
    
    ll query(ll i) {
        ll sum = 0;
        for ( ; i > 0 ; i -= i & -i)
            sum += tree[i];
        return sum;
    }
    
    ll findKth(ll k) {
        ll l = 1, r = tree.size() - 1;
        while (l < r) {
            ll mid = (l + r) / 2;
            if (query(mid) < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};

int main() {
    fastio;
    ll n;
    cin >> n;
    vector<ll> arr(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    vector<ll> positions(n);
    for (ll i = 0; i < n; i++)
        cin >> positions[i];
    
    FenwickTree fenwick(n);
    for (ll i = 1; i <= n; i++)
        fenwick.update(i, 1);
    for (ll i = 0; i < n; i++) {
        ll pos = positions[i];
        ll actualPos = fenwick.findKth(pos);
        cout << arr[actualPos] << " ";
        fenwick.update(actualPos, -1);
    }
    return 0;
}
