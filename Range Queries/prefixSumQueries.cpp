#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    ll sum, pref;
    node(ll sum, ll pref) : sum(sum), pref(pref) {}
    node(ll x = 0) : sum(x), pref(max(0LL, x)) {}
    friend node operator+(const node &a, const node &b) {
        return {a.sum + b.sum, max(a.pref, a.sum + b.pref)};
    }
};

void build(vector<node>& tree, vector<ll>& arr, ll i, ll l, ll r) {
    if (l == r) {
        tree[i] = node(arr[l]);
        return;
    }
    ll m = (l + r) / 2;
    build(tree, arr, 2 * i + 1, l, m);
    build(tree, arr, 2 * i + 2, m + 1, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

void update(vector<node>& tree, vector<ll>& arr, ll i, ll l, ll r, ll pos, ll val) {
    if (l == r) {
        arr[pos] = val;
        tree[i] = node(val);
        return;
    }
    ll m = (l + r) / 2;
    if (pos <= m)
        update(tree, arr, 2 * i + 1, l, m, pos, val);
    else
        update(tree, arr, 2 * i + 2, m + 1, r, pos, val);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

node query(vector<node>& tree, ll i, ll j, ll l, ll r, ll id) {
    if (i >= l && j <= r)
        return tree[id];
    if (r < i || l > j)
        return node(0);
    ll m = (i + j) / 2;
    node q1 = query(tree, i, m, l, r, 2 * id + 1);
    node q2 = query(tree, m + 1, j, l, r, 2 * id + 2);
    return q1 + q2;
}

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n + 1);
    vector<node> tree(4 * n);
    for (ll i = 1; i <= n; ++i)
        cin >> arr[i];
    build(tree, arr, 0, 1, n);
    while (q-- > 0) {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
            update(tree, arr, 0, 1, n, x, y);
        else
            cout << query(tree, 1, n, x, y, 0).pref << "\n";
    }
}
