#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[5001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int k, q; cin >> q >> k;
	dp[0] = 1;

	while (q--) {
		char t; int x; cin >> t >> x;
		if (t == '+') {
			for (int i=k;i>=x;i--) {
				dp[i] += dp[i-x];
				dp[i] %= 998244353;
			}
		} else {
			for (int i=0;i<=k-x;i++) {
				dp[i+x] -= dp[i]-998244353;
				dp[i+x] %= 998244353;
			}
		}
		cout << dp[k] << "\n";
	}
}