#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& arr, vector<bool>& vis, int i) {
    vis[i] = true;
    for (int j : arr[i]) {
        if (!vis[j]) {
            dfs(arr, vis, j);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> right;
    int left = -1;
    vector<vector<int>> arr(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int len = 0;
    vector<bool> vis(n, false);
    
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            len++;
            if (left == -1)
                left = i + 1;
            else
                right.push_back(i + 1);
            dfs(arr, vis, i);
        }
    }

    if (len == 1) {
        cout << 0 << endl;
        return 0;
    }

    cout << len - 1 << endl;
    for (int x : right) {
        cout << left << " " << x << endl;
        left = x;
    }

    return 0;
}
