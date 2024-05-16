#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hps.in","r",stdin);
	freopen("hps.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	char c;
	int win[n+1];
	int dp[n+1][k+1][3];
	
	// for I games, J changes, & current gesture.
	for (int i=0;i<n;i++) {
		cin >> c;
		if (c == 'H') {win[i+1] = 0;}
		else if (c == 'P') {win[i+1] = 1;}
		else {win[i+1] = 2;}
	}
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=k;j++) {
			for (int l=0;l<3;l++) {dp[i][j][l] = 0;}
		}
	}

	for (int i=1;i<=n;i++) {
		for (int j=0;j<=k;j++) {
			for (int a=0;a<3;a++) {
				dp[i][j][a] = dp[i-1][j][a];
			}
		} // update

		for (int j=0;j<k;j++) {
			for (int a=0;a<3;a++) {
				for (int b=0;b<3;b++) {
					if (a != b) {
						dp[i][j+1][b] = max(dp[i][j+1][b], dp[i][j][a]);
					}
				}
			} 
		} // switch?
		
		for (int j=0;j<=k;j++) {
			dp[i][j][win[i]]++;
		} // win?
	}

	int ans = 0;
	for (int i=0;i<=k;i++) {
		ans = max(ans, dp[n][i][0]);
		ans = max(ans, dp[n][i][1]);
		ans = max(ans, dp[n][i][2]);
	}
	cout << ans << '\n';
}
