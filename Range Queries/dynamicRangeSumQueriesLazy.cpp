#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
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
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

void propagate(vector<ll>& tree, vector<ll>& lazy, ll i, ll l, ll r) {
    if (lazy[i] != 0) {
        tree[i] += lazy[i] * (r - l + 1);
        if (l != r) {
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }
}

ll query(vector<ll>& tree, vector<ll>& lazy, ll i, ll l, ll r, ll ql, ll qr) {
    propagate(tree, lazy, i, l, r);
    if (ql > r || qr < l)
        return 0;
    if (ql <= l && qr >= r)
        return tree[i];
    ll m = (l + r) / 2;
    return query(tree, lazy, 2 * i + 1, l, m, ql, qr) + query(tree, lazy, 2 * i + 2, m + 1, r, ql, qr);
}

void updatePoint(vector<ll>& arr, vector<ll>& tree, vector<ll>& lazy, ll i, ll l, ll r, ll pos, ll new_val) {
    propagate(tree, lazy, i, l, r);
    if (l == r) {
        tree[i] = new_val;
        return;
    }
    ll m = (l + r) / 2;
    if (pos <= m)
        updatePoint(arr, tree, lazy, 2 * i + 1, l, m, pos, new_val);
    else
        updatePoint(arr, tree, lazy, 2 * i + 2, m + 1, r, pos, new_val);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

int main() {
    ll n, q, ch, l, r, val;
    cin >> n >> q;
    vector<ll> arr(n);
    ll size = ceil(log2(n)) + 1;
    size = pow(2, size) - 1;
    vector<ll> tree(size, 0), lazy(size, 0);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    build(arr, tree, 0, 0, n - 1);

    while (q-- > 0) {
        cin >> ch >> l >> r;
        if (ch == 1){
            l--;
            updatePoint(arr, tree, lazy, 0, 0, n - 1, l, r);
        }
        else{
            l--, r--;
            cout << query(tree, lazy, 0, 0, n - 1, l, r) << "\n";
        }
    }
}
