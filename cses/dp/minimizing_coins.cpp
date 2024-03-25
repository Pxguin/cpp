#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x;
	int c[n]; dp[0] = 0;
	for (int i=0;i<n;i++) {cin >> c[i]; dp[c[i]] = 1;}
	for (int i=1;i<=x;i++) {
		dp[i] = INT_MAX;
		for (int j=0;j<n;j++) {
			if (i-c[j] >= 0 && dp[i-c[j]] != INT_MAX) {dp[i] = min(dp[i], dp[i-c[j]]+1);}
		}
	}
	cout << ((dp[x]==INT_MAX) ? -1 : dp[x]) << "\n";  
}
