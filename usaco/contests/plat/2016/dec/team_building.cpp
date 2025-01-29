#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);

	int n, m, k; cin >> n >> m >> k;
	int mod = 1e9+9;
	vector<int> a(n), b(m);
	F0R(i,n) {cin >> a[i];}
	F0R(i,m) {cin >> b[i];}

	v<v<v<int>>> dp(n,v<v<int>>(m,v<int>(k+1,0)));
	auto add = [&](int& a, int b)->void {a = (a+b)%mod;};
	F0R(i,n) {F0R(j,m) {dp[i][j][1]=(a[i]>b[j]);}}

	FOR(sz,1,k) {
		vector<int> ps(m+1,0);
		F0R(fj,n) {
			vector<int> cur(m+1,0);
			F0R(fn,m) {
				add(ps[fn],cur[fn]);
				if (a[fj]>b[fn]) {add(dp[fj][fn][sz+1],ps[fn]);}
				if (fj) {add(cur[fn+1],dp[fj-1][fn][sz]);}
				add(cur[fn+1],cur[fn]);
			}
		}
	}
	int ans = 0;
	F0R(i,n) {F0R(j,m) {add(ans,dp[i][j][k]);}}
	cout << ans << '\n';
}