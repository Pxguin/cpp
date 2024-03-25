#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

ll dp[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x;
	dp[0] = 1;
	pair<int,int> b[n];

	for (int i=0;i<n;i++) {cin >> b[i].f;}
	for (int i=0;i<n;i++) {cin >> b[i].s;}

	for (int i=0;i<n;i++) {
		int h = b[i].f, s1 = b[i].s;
		for (int j=x-h;j>=0;j--) {
			if (dp[j]) {
				dp[j+h] = max(dp[j+h], dp[j]+s1);
			}
		}
	}
	ll mx = 0;
	for (int i=0;i<=x;i++) {mx = max(mx, dp[i]);}
	cout << --mx;

}
