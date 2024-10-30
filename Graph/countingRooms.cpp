#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& arr, int i, int j, int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m || arr[i][j] == '#')
        return;
    arr[i][j] = '#';
    dfs(arr, i + 1, j, n, m);
    dfs(arr, i, j + 1, n, m);
    dfs(arr, i - 1, j, n, m);
    dfs(arr, i, j - 1, n, m);
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<char>> arr(n, vector<char>(m));
    char a;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin>>a;
            arr[i][j] = a;
        }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == '.') {
                dfs(arr, i, j, n, m);
                ans++;
            }
    cout<<ans;
    return 0;
}
