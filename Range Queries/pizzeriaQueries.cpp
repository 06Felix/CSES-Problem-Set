#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define llm LLONG_MAX
typedef long long ll;

void build(vector<ll>& down, vector<ll>& up, vector<ll>& p, ll i, ll l, ll r) {
    if (l > r)
        return;
    if (l == r) {
        down[i] = p[l] - l;
        up[i] = p[l] + l;
        return;
    }
    ll m = (l + r) / 2;
    build(down, up, p, 2 * i + 1, l, m);
    build(down, up, p, 2 * i + 2, m + 1, r);
    down[i] = min(down[2 * i + 1], down[2 * i + 2]);
    up[i] = min(up[2 * i + 1], up[2 * i + 2]);
}

void update(vector<ll>& tree, ll i, ll l, ll r, ll pos, ll val) {
    if (l == r) {
        tree[i] = val;
        return;
    }
    ll m = (l + r) / 2;
    if (pos <= m)
        update(tree, 2 * i + 1, l, m, pos, val);
    else
        update(tree, 2 * i + 2, m + 1, r, pos, val);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

ll query(vector<ll>& tree, ll i, ll l, ll r, ll ql, ll qr) {
    if (ql > r || qr < l)
        return llm;
    if (ql <= l && r <= qr)
        return tree[i];
    ll m = (l + r) / 2;
    return min(query(tree, 2 * i + 1, l, m, ql, qr), query(tree, 2 * i + 2, m + 1, r, ql, qr));
}

int main() {
    fastio;
    ll n, q;
    cin >> n >> q;
    vector<ll> p(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> p[i];
    ll size = 4 * n;
    vector<ll> down(size, llm), up(size, llm);
    build(down, up, p, 0, 1, n);
    while (q--) {
        ll t, k, x;
        cin >> t;
        if (t == 1) {
            cin >> k >> x;
            update(down, 0, 1, n, k, x - k);
            update(up, 0, 1, n, k, x + k);
        }
        else {
            cin >> k;
            ll d = query(down, 0, 1, n, 1, k) + k;
            ll u = query(up, 0, 1, n, k, n) - k;
            cout << min(d, u) << "\n";
        }
    }
    return 0;
}
