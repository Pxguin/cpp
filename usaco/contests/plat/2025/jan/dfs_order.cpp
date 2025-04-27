#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)

const int MAX_N = 750;
int cost[MAX_N][MAX_N+1] = {0}, dp[MAX_N][MAX_N], ps[MAX_N][MAX_N+1] = {0};

int main() {
    int n; cin >> n;
    for (int i=1;i<n;i++) {
        for (int j=0;j<i;j++) {
            cin >> cost[j][i];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=n-1;j>=0;j--) {
            dp[i][j] = INT_MAX; // ps[i][j]: cost to remove all edges (i,k) such that k>j
            ps[i][j] = ps[i][j+1]-min(0,cost[i][j+1]);
        }
    }
    dp[n-1][n-1] = 0; // dp[i][j]: min cost so subtree of i has all nodes [i,j]
    for (int i=n-2;i>=0;i--) {
        dp[i][i] = ps[i][i]; // base case
        for (int j=i;j<n;j++) {
            for (int k=j+1;k<n;k++) { // combine two ranges
                chmin(dp[i][k],dp[i][j]-ps[i][j] + max(0,cost[i][j+1])+dp[j+1][k]+ps[i][k]);
            }
        }
    }
    cout << dp[0][n-1] << '\n';
}