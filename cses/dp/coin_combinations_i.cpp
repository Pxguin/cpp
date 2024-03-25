#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[1000001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x;
	int c[n]; 
	dp[0] = 1;
	for (int i=0;i<n;i++) {cin >> c[i];}

	for (int i=1;i<=x;i++) {
		for (int j : c) {
			if (i-j >= 0) {dp[i] += dp[i-j];}
		}
		dp[i] %= 1000000007;
	}
	cout << dp[x];
}
