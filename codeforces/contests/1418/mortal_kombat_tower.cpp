#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

void solve() {
	int n; cin >> n;
	bool a[n];
	for (int i=0;i<n;i++) {cin >> a[i];}

	pair<int,int> dp[n+2];
	for (int i=0;i<n+2;i++) {dp[i].f = INT_MAX; dp[i].s = INT_MAX;}
	dp[0].f = 0;
	// f = friend
	// s = you

	for (int i=0;i<n;i++) {
		if (dp[i].f != INT_MAX) {
			dp[i+1].s = min(dp[i+1].s, dp[i].f+a[i]);
			dp[i+2].s = min(dp[i+2].s, dp[i].f+a[i]+a[i+1]);
		} 
		if (dp[i].s != INT_MAX) {
			dp[i+1].f = min(dp[i+1].f, dp[i].s);
			dp[i+2].f = min(dp[i+2].f, dp[i].s);
		}
	}
	cout << min(dp[n].f, dp[n].s) << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}
