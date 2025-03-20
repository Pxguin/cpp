#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int n; cin >> n;
	unordered_map<string,int> hsh;
	int cur = 0; string s1,s2;
	vector<pii> a(n);
	F0R(i,n) {
		cin >> s1 >> s2;
		if (hsh.count(s1)) {a[i].f = hsh[s1];}
		else {a[i].f = ++cur; hsh[s1] = cur;}
		if (hsh.count(s2)) {a[i].s = hsh[s2];}
		else {a[i].s = ++cur; hsh[s2] = cur;}
	}
	vector<vector<int>> dp((1<<n),vector<int>(n,INT_MAX));
	F0R(i,n) {dp[1<<i][i]=0;}

	F0R(i,(1<<n)) {
		F0R(j,n) {
			if (!((1<<j)&i)) {continue;}
			// try all other last
			F0R(k,n) {
				if ((1<<k)&i) {continue;}
				if (a[k].s==a[j].s || a[k].f==a[j].f) {
					dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k],dp[i][j]);
				} dp[i|(1<<k)][j] = min(dp[i|(1<<k)][j],dp[i][j]+1);
			}
		}
	} 
	int ans = 16;
	F0R(i,n) {ans = min(ans,dp[(1<<n)-1][i]);}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}