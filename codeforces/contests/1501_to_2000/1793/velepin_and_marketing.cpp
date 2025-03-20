#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector<int> a(n);
	vector<int> dp(n+1,0), ps(n+1,0);
	vector<int> ans(n+2,0);
	F0R(i,n) {cin >> a[i];}
	sort(a.begin(),a.end());

	FOR(i,1,n+1) {
		if (i-a[i-1]>=0) {
			dp[i] = 1+ps[i-a[i-1]];
			chmax(ans[dp[i]+(n-i)],i);
		} else {chmax(ans[n-a[i-1]+1],i);}

		ps[i] = max(ps[i-1],dp[i]);
	}
	for (int i=n;i;i--) {chmax(ans[i],ans[i+1]);}
	int d, q; cin >> q;
	while (q--) {
		cin >> d;
		cout << ans[d] << '\n';
	}
}