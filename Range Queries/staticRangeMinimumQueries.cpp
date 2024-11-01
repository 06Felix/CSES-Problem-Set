#include <bits/stdc++.h>
using namespace std;
#define llm LLONG_MAX
typedef long long ll;
void build(ll arr[], vector<ll>& tree, ll i, ll l, ll r){
    if(l > r)
        return;
    if(l == r){
        tree[i] = arr[l];
        return;
    }
    ll m = (l + r) / 2;
    build(arr, tree, 2 * i + 1, l, m);
    build(arr, tree, 2 * i + 2, m + 1, r);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}
ll query(vector<ll>& tree, ll i, ll j, ll l, ll r, ll id){
    if(i >= l and j <= r)
        return tree[id];
    if(r < i || l > j)
        return llm;
    int m = (i + j) / 2;
    return min(query(tree, i, m, l, r, 2 * id + 1), query(tree, m + 1, j, l, r, 2 * id + 2));
}
int main(){
    ll n, q, l ,r;
    cin >> n >> q;
    ll arr[n];
    ll size = ceil(log2(n)) + 1;
    size = pow(2, size) - 1;
    vector<ll> tree(size, llm);
    for(ll i = 0 ; i < n ; i++)
        cin >> arr[i];
    build(arr, tree, 0, 0, n - 1);
    while(q-- > 0){
        cin >> l >> r;
        l--;
        r--;
        cout << query(tree, 0, n - 1, l, r, 0) << "\n";
    }
}