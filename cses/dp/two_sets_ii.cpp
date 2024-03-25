#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define MAX_N 150000

ll dp[MAX_N+1];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	dp[0] = 1;
	int sum = 0;
	for(int i=1;i<=n;i++) {sum += i;}

	if (sum%2) {cout << 0; return 0;}

	for (int i=1;i<=n;i++) {
		for (int j=sum/2;j>=i;j--) {
			if (dp[j-i]) {dp[j] += dp[j-i]; dp[j] %= MOD*2;}
		}
	}
	cout << dp[sum/2]/2;
}
