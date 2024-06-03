#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("tilechng.in","r",stdin);
    freopen("tilechng.out","w",stdout);
    int n, m; cin >> n >> m;
    int a[n]; 
    for (int i=0;i<n;i++) {cin >> a[i];}

    vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX)); dp[0][0] = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (dp[i][j] == INT_MAX) {continue;}
            for (int k=0;k<=100;k++) {
                if (j+k*k <= m) {dp[i+1][j+k*k]=min(dp[i+1][j+k*k],dp[i][j]+(a[i]-k)*(a[i]-k));}
            }
        }
    }
    cout << (dp[n][m]==INT_MAX ? -1 : dp[n][m]) << '\n';
}