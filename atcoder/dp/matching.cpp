#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 21, mod = 1e9+7;
int dp[1<<MAX_N] = {0};
int adj[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> adj[i][j];
        }
    }
    dp[0] = 1;
    for (int i=0;i<(1<<n);i++) {
        int j = __builtin_popcount(i);
        for (int k=0;k<n;k++) {
            if (!((1<<k)&i) && adj[j][k]) {
                dp[i^(1<<k)] = (dp[i^(1<<k)]+dp[i])%mod;
            }
        }
    }
    cout << dp[(1<<n)-1] << '\n';
}
