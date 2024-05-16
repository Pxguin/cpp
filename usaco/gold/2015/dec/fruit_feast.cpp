#include <bits/stdc++.h>
using namespace std;

int dp[5000001];

int main() {
	freopen("feast.in","r",stdin);
	freopen("feast.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t, a, b; cin >> t >> a >> b;
	dp[0] = 1;
	for (int i=0;i<=t;i++) {
		if (dp[i]) {
			if (i+a <= t) {dp[i+a] = 1;}
			if (i+b <= t) {dp[i+b] = 1;}
			dp[i/2] = 1;
		}
	}
	int ans = 0;
	for (int i=0;i<=t;i++) {
		if (dp[i]) {
			if (i+a <= t) {dp[i+a] = 1;}
			if (i+b <= t) {dp[i+b] = 1;}
			ans = i;
		}
	}
	cout << ans << '\n';
}
