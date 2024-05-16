#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	int a[n];

	int dp[n+1][k+1][n];
	// ith group, j changes, kth size
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=k;j++) {
			for (int l=0;l<=n;l++) {dp[i][j][l] = 0;}
		}
	}
	for (int i=0;i<n;i++) {cin >> a[i];}
	for (int i=0;i<n;i++) {
		for (int j=0;j<k;j++) {
			int mn = INT_MAX;
			for (int l=0;l<n;l++) {mn = min(mn, dp[i][j][l]);}
			for (int l=0;l<n;l++) {dp[i][j+1][l] = min(dp[i][j+1][l],mn);}
		}
		// change to a net

		for (int j=0;j<=k;j++) {
			for (int l=0;l<n;l++) {
				if (a[l] >= a[i] && dp[i][j][l] != INT_MAX) {
					dp[i+1][j][l] = dp[i][j][l]+(a[l]-a[i]);
				} else {dp[i+1][j][l] = INT_MAX;}
			}
		}
		// get current snake (mark INT_MAX if impossible)
	}

	int ans = INT_MAX;
	for (int i=0;i<=k;i++) {
		for (int j=0;j<n;j++) {
			ans = min(ans,dp[n][i][j]);
		}
	}
	cout << ans << '\n';
}
