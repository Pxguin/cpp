#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("help.in","r",stdin);
	freopen("help.out","w",stdout);

	int n, l, r; cin >> n;
	vector<int> pnts(2*n,0);

	F0R(i,n) {
		cin >> l >> r;
		pnts[--l]++; pnts[--r]--;
	}
	int mod = 1e9+7;

	vector<int> two(n,1);
	FOR(i,1,n) {two[i]=two[i-1]*2%mod;}

	int cnt = 0, ans = 0;
	F0R(i,2*n) {
		cnt += pnts[i];
		if (pnts[i]==1) {ans = (ans+two[n-cnt])%mod;}
	} cout << ans << '\n';
}