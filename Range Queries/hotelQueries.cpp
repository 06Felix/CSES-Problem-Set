#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;

void build(vector<ll>& arr, vector<ll>& tree, ll i, ll l, ll r) {
    if (l > r)
        return;
    if (l == r) {
        tree[i] = arr[l];
        return;
    }
    ll m = (l + r) / 2;
    build(arr, tree, 2 * i + 1, l, m);
    build(arr, tree, 2 * i + 2, m + 1, r);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

void query(vector<ll>& tree, ll l, ll r, ll id, ll val) {
    if (l == r) {
        tree[id] -= val;
        cout << l + 1 << " ";
        return;
    }
    ll m = (l + r) / 2;
    if (tree[2 * id + 1] >= val)
        query(tree, l, m, 2 * id + 1, val);
    else
        query(tree, m + 1, r, 2 * id + 2, val);
    tree[id] = max(tree[2 * id + 1], tree[2 * id + 2]);
}

int main() {
    fastio;
    ll n, q, x;
    cin >> n >> q;
    vector<ll> arr(n);
    ll size = ceil(log2(n)) + 1;
    size = pow(2, size) - 1;
    vector<ll> tree(size, 0);
    for (ll i = 0; i < n; i++) cin >> arr[i];
    build(arr, tree, 0, 0, n - 1);
    while (q--) {
        cin >> x;
        if(tree[0] < x)
            cout << "0 ";
        else
            query(tree, 0, n - 1, 0, x);
    }
    return 0;
}
