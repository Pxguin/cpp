#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[1000001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, x; cin >> n >> x;
	int c[n]; dp[0] = 1;
	for (int i=0;i<n;i++) {cin >> c[i];}

	for (int i=0;i<n;i++) {
		for (int j=1;j<=x;j++) {
			if (j-c[i] >= 0) {dp[j] += dp[j-c[i]];}
			dp[j] %= 1000000007;
		}
	}
	cout << dp[x];
}
