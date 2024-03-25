#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[1000001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	dp[0] = 1;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=6;j++) {
			if (i-j >= 0) {dp[i] += dp[i-j];}
		}
		dp[i] %= 1000000007;
	}
	cout << dp[n] << "\n";
}
