#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	freopen("cowmbat.in","r",stdin);
	freopen("cowmbat.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, x; cin >> n >> m >> x;
	char c;
	int cur[n];
	for (int i=0;i<n;i++) {cin >> c; cur[i] = c-'a';}

	// floyd-warshall
	vector<vector<int>> dist(m, vector<int>(m, INT_MAX));
	for (int i=0;i<m;i++) {
		for (int j=0;j<m;j++) {
			cin >> dist[i][j];
		}
	}
	for (int k=0;k<m;k++) {
		for (int i=0;i<m;i++) {
			for (int j=0;j<m;j++) {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	
	// dp[i][j] max for string 0...i-1, assuming last character is j
	vector<vector<int>> ps(m, vector<int>(n+x, 0));
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {ps[i][j+1] = dist[cur[j]][i]+ps[i][j];}
	}

	vector<vector<ll>> dp(n+x, vector<ll>(m,INT_MAX));

	for (int i=0;i<m;i++) {dp[x][i] = ps[i][x];}

	for (int i=x;i<=n-1;i++) {
		for (int j=0;j<m;j++) {
			for (int k=0;k<m;k++) {
				if (j == k) {dp[i+1][j] = min(dp[i+1][j], dp[i][j]+dist[cur[i]][j]);}
				else {dp[i+x][k] = min(dp[i+x][k], dp[i][j]+(ps[k][i+x]-ps[k][i]));}
			}
		}
	}
	ll ans = LLONG_MAX;

	for (int i=0;i<m;i++) {ans = min(ans, dp[n][i]);}
	cout << ans << '\n';
}
