#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;
typedef long long ll;

int main() {
    ll n, m, q, u, v, w, src, dst;
    cin >> n >> m >> q;
    vector<vector<ll>> arr(n, vector<ll>(n, LONG_MAX));
    for (ll i = 0; i < m; ++i){
        cin >> u >> v >> w;
        u--;
        v--;
        arr[u][v] = min(arr[u][v], w);
        arr[v][u] = min(arr[v][u], w);
    }
    for (ll i = 0; i < n; ++i)
        arr[i][i] = 0;
    for(ll k = 0 ; k < n ; k++)
        for(ll i = 0 ; i < n ; i++)
            for(ll j = i + 1 ; j < n ; j++)
                if(arr[i][k] != LONG_MAX and arr[k][j] != LONG_MAX and arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                    arr[j][i] = arr[i][j];
                }
    for(ll i = 0 ; i < q ; i++, cout<<"\n"){
        cin >> src >> dst;
        src--;
        dst--;
        arr[src][dst] == LONG_MAX ? cout<< -1 : cout<<arr[src][dst];
    }
    return 0;
}
