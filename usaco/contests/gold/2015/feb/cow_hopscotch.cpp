#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int mod = 1e9+7;
void add(int& a, int b) {a = (a+b)%mod;}
void sub(int& a, int b) {a = (a-b+mod)%mod;}
int add2(int a, int b) {return (a+b)%mod;}
int sub2(int a, int b) {return (a-b+mod)%mod;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("hopscotch.in","r",stdin);
	freopen("hopscotch.out","w",stdout);
	
	int r, c, k; cin >> r >> c >> k;
	v<v<int>> g(r,v<int>(c));
	v<v<int>> dp(r,v<int>(c,0));
	v<v<int>> ps(r+1,v<int>(c+1,0));
	v<v<int>> pos(k);
	dp[0][0] = ps[1][1] = 1;

	F0R(i,r) {
		F0R(j,c) {
			cin >> g[i][j]; g[i][j]--;
			int col = g[i][j];
			pos[col].pb(j);
			ps[i][1] = ps[1][j] = 1;
		}
	}
	F0R(i,k) {
		sort(pos[i].begin(),pos[i].end());
		pos[i].resize(distance(pos[i].begin(),unique(pos[i].begin(),pos[i].end())));
	}
	v<v<int>> bit(k); // build bit for each color (only store columns that each color appears in)
	F0R(i,k) {bit[i] = v<int>(pos[i].size()+1,0);}

	auto upd = [&](int i, int i2, int v) {
		for (; i2<bit[i].size(); i2+=(i2&(-i2))) {add(bit[i][i2],v);}
	};
	auto get = [&](int i, int i2) {
		int sum = 0;
		for (; i2; i2-=(i2&(-i2))) {add(sum,bit[i][i2]);}
		return sum;
	};
	upd(g[0][0],1,1);

	FOR(i,1,r) {
		for (int j=c-1;j;j--) {
			int col = g[i][j];
			int idx = lower_bound(pos[col].begin(),pos[col].end(),j)-pos[col].begin(); // find the index in the bit
			dp[i][j] = ps[i][j]; // prefix sum minus bit retrieved sum
			if (idx) {sub(dp[i][j],get(col,idx));}
			upd(g[i][j],idx+1,dp[i][j]);
		}
		FOR(j,1,c) {
			ps[i+1][j+1] = sub2(add2(ps[i][j+1],add2(dp[i][j],ps[i+1][j])),ps[i][j]);
		}
	} cout << dp[r-1][c-1] << '\n';
}