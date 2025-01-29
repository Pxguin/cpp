#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("taming.in","r",stdin);
	freopen("taming.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int a[n];
	for (int i=0;i<n;i++) {cin >> a[i];}

	vector<vector<vector<int>>> dp(n,vector<vector<int>>(n+1,vector<int>(n+1,101)));
	dp[0][1][0] = (a[0]!=0);
	for (int i=1;i<n;i++) { // ith log
		for (int j=0;j<n;j++) {
			for (int k=0;k<i;k++) {
				if (a[i]) {
					// change to breakout
					dp[i][j+1][0] = min(dp[i][j+1][0], dp[i-1][j][k]+1);
					// change not to breakout
					dp[i][j][k+1] = min(dp[i][j][k+1], dp[i-1][j][k]+(a[i]!=k+1));
				} else {
					// change to not breakout
					dp[i][j][k+1] = min(dp[i][j][k+1], dp[i-1][j][k]+1);
					// keep as breakout
					dp[i][j+1][0] = min(dp[i][j+1][0], dp[i-1][j][k]);
				}
			}
		}
	}

	for (int i=1;i<=n;i++) {
		int ans = 101;
		for (int j=0;j<=n;j++) {
			ans = min(ans, dp[n-1][i][j]);
		}
		cout << ans << '\n';
	}
}
