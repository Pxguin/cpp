#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	freopen("checklist.in","r",stdin);
	freopen("checklist.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int h, g; cin >> h >> g;
	vector<vector<pii>> cows(2,vector<pii>(max(g,h)));
	F0R(i,h) {cin >> cows[0][i].f >> cows[0][i].s;}
	F0R(i,g) {cin >> cows[1][i].f >> cows[1][i].s;}

	vector<vector<vector<ll>>> dp(h+2,vector<vector<ll>>(g+2,vector<ll>(2,LLONG_MAX)));
	auto dist = [&](pii x, pii y) {return (ll)(y.f-x.f)*(y.f-x.f)+(y.s-x.s)*(y.s-x.s);};
	dp[1][0][0] = 0;

	F0R(i,h+1) {
		F0R(j,g+1) {
			F0R(k,2) {
				if (dp[i][j][k] != LLONG_MAX) {
					if (k==0) {
						// try visiting h
						dp[i+1][j][0] = min(dp[i+1][j][0],dp[i][j][k]+dist(cows[0][i-1],cows[0][i]));
						// try visiting g
						dp[i][j+1][1] = min(dp[i][j+1][1],dp[i][j][k]+dist(cows[0][i-1],cows[1][j]));
					} else {
						// h
						dp[i+1][j][0] = min(dp[i+1][j][0],dp[i][j][k]+dist(cows[1][j-1],cows[0][i]));
						// g
						dp[i][j+1][1] = min(dp[i][j+1][1],dp[i][j][k]+dist(cows[1][j-1],cows[1][j]));
					}
				}
			}
		}
	} cout << dp[h][g][0] << '\n';
} 	