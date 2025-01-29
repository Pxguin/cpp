#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("teamwork.in","r",stdin);
	freopen("teamwork.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n,k; cin >> n >> k;
	int a[n];

	for (int i=0;i<n;i++) {cin >> a[i];}

	vector<vector<int>> ranges(n, vector<int>(k,0));
	for (int i=0;i<n;i++) {
		int mx = 0;
		for (int j=i;j<i+k;j++) {
			if (j < n) {
				mx = max(mx, a[j]);
				ranges[i][j-i] = mx;
			}
		}
	}

	vector<int> dp(n+k, 0);
	for (int i=0;i<n;i++) {
		for (int j=0;j<k;j++) {
			dp[i+j+1] = max(dp[i+j+1], dp[i]+((j+1)*ranges[i][j]));
		}
	}
	cout << dp[n];
}
