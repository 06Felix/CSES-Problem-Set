#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
const int maxX = 1e6;
const ll MOD = 1e9+7;

int N, X, c;
ll dp[maxX + 1];

int main(){
    fastio;
    scanf("%d %d", &N, &X);

    dp[0] = 1;
    for(int i = 0; i < N; i++){
        scanf("%d", &c);
        for(int j = 0; j <= X - c; j++)
            dp[j + c] = (dp[j + c] + dp[j]) % MOD;
    }
    printf("%lld\n", dp[X]);
}

