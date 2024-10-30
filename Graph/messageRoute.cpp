#include <bits/stdc++.h>
using namespace std;

int ct = 0;

void path(vector<int>& arr, int i) {
    if (i == 0) {
        cout << ct + 1 << "\n1 ";
        return;
    }
    ct++;
    path(arr, arr[i]);
    cout << (i + 1) << " ";
}

void bfs(vector<vector<int>>& arr, int n) {
    queue<int> q;
    vector<int> parent(n, -1);
    parent[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int j : arr[cur]) {
            if (parent[j] == -1) {
                parent[j] = cur;
                if (j == n - 1) {
                    path(parent, n - 1);
                    return;
                }
                q.push(j);
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    bfs(arr, n);
    return 0;
}
