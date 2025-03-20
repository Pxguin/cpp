#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int n, k; cin >> n >> k;
	vector<vector<int>> a(n+3,vector<int>(n+3,0));
	FOR(i,2,n+2,1) {
		FOR(j,i,n+2,1) {cin >> a[i][j];}
	}
	vector<vector<int>> dp(n+2); // k max 0...i (regardless if i-1 is blank or not)
	dp[0].pb(0); dp[1].pb(0);
	FOR(i,2,n+2,1) {
		vector<int> ptr(n+2,0);
		priority_queue<pii> cur;
		FOR(j,0,i,1) {
			cur.push({dp[j][0]+a[j+2][i],j});
		}
		while (cur.size()) {
			pii mx = cur.top(); cur.pop();
			dp[i].pb(mx.f);
			if (++ptr[mx.s]!=dp[mx.s].size()) {cur.push({dp[mx.s][ptr[mx.s]]+a[mx.s+2][i],mx.s});}
			if (dp[i].size() == k) {break;}
		}
	}
	for (int i : dp[n+1]) {cout << i << ' ';} cout << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}