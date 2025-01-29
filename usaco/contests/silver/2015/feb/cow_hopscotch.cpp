#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int mod = 1e9+7;
void add(int& a, int b) {a = (a+b)%mod;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("hopscotch.in","r",stdin);
	freopen("hopscotch.out","w",stdout);
	
	int r, c, k; cin >> r >> c >> k;
	v<v<int>> g(r,v<int>(c));
	v<v<int>> dp(r,v<int>(c,0));
	dp[0][0] = 1;

	F0R(i,r) {
		F0R(j,c) {
			cin >> g[i][j];
			F0R(i1,i) {
				F0R(j1,j) {
					if (g[i][j]==g[i1][j1]) {continue;} // only get squares with different color
					add(dp[i][j],dp[i1][j1]);
				}
			}
		}
	} cout << dp[r-1][c-1] << '\n';
}