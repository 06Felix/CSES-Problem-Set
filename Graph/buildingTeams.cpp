#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int>>& arr, int n) {
    vector<int> team(n, 0);
    for (int i = 0; i < n; ++i) {
        if (team[i] != 0)
            continue;
        queue<int> q;
        q.push(i);
        team[i] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int j : arr[cur]) {
                if (team[j] == team[cur]) {
                    cout << "IMPOSSIBLE\n";
                    return;
                }
                if (team[j] == 0) {
                    team[j] = team[cur] ^ 3;
                    q.push(j);
                }
            }
        }
    }
    for (int x : team)
        cout << x << " ";
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