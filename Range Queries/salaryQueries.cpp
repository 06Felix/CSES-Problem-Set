#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void update(vector<ll>& bit, ll n, ll i, ll val) {
    for (; i <= n; i += i & (-i))
        bit[i] += val;
}

void add(vector<ll>& bit, vector<int>& vals, int x, int b) {
    int ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
    update(bit, vals.size(), ind, b);
}

ll sum(vector<ll>& bit, int x) {
    ll res = 0;
    for (; x; x -= x & (-x))
        res += bit[x];
    return res;
}

ll query(vector<ll>& bit, vector<int>& vals, int x) {
    int ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
    return sum(bit, ind);
}

int main() {
    ll n, q;
    cin >> n >> q;
    vector<int> arr(n), vals;
    vector<array<int, 3>> queries;
    for (ll i = 0; i < n; i++) cin >> arr[i];
    vals = arr;
    for (ll i = 0; i < q; i++) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        queries.push_back({t == '?', a, b});
        if (t == '!') vals.push_back(b);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    vector<ll> bit(vals.size() + 1, 0);
    for (ll i = 0; i < n; i++)
        add(bit, vals, arr[i], 1);
    for (auto u : queries) {
        u[1]--;
        if (u[0] == 0) {
            add(bit, vals, arr[u[1]], -1);
            arr[u[1]] = u[2];
            add(bit, vals, arr[u[1]], 1);
        }
        else
            cout << query(bit, vals, u[2]) - query(bit, vals, u[1]) << "\n";
    }
}
