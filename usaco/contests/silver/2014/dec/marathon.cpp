#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second

int main() {
	freopen("marathon.in","r",stdin);
	freopen("marathon.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	pii c[n];
	for (int i=0;i<n;i++) {cin >> c[i].f >> c[i].s;}

	auto dist = [&](int a, int b) {return abs(c[a].f-c[b].f)+abs(c[a].s-c[b].s);};

	vector<vector<int>> dp(n, vector<int>(k+1,INT_MAX)); dp[0][0] = 0;
	for (int i=0;i<n-1;i++) {
		for (int j=0;j<=k;j++) {
			if (dp[i][j] == INT_MAX) {continue;}
			for (int h=0;h<=k-j;h++) {
				if (i+h+1 < n) {dp[i+h+1][j+h]=min(dp[i+h+1][j+h],dp[i][j]+dist(i+h+1,i));}
			}
		}
	}
	int ans = INT_MAX;
	for (int i=0;i<=k;i++) {
		ans = min(ans, dp[n-1][i]);
	} cout << ans << '\n';
}
