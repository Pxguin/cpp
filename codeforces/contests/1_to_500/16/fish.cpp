#include <bits/stdc++.h>
using namespace std;

#define ld long double

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	ld a[n][n];
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cin >> a[i][j];
		}
	}

	vector<ld> dp(1<<n,0); dp[(1<<n)-1] = 1;
	for (int i=(1<<n)-1;i>1;i--) {
		for (int j=0;j<n;j++) {
			if ((i&(1<<j))==0) {continue;}
			for (int k=0;k<n;k++) {
				// try for all others to eat this fish
				if ((i&(1<<k))==0) {continue;}
				dp[i^(1<<j)] += dp[i]*a[k][j];
			}
		}
	}
	ld total = 0;
	for (int i=0;i<n;i++) {total += dp[1<<i];}
	cout << fixed << setprecision(6);
	for (int i=0;i<n;i++) {cout << dp[1<<i]/total << ' ';}
}
