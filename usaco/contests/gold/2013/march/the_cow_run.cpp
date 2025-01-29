#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("cowrun.in","r",stdin);
	freopen("cowrun.out","w",stdout);
	
	int n; cin >> n;
	vector<int> l(n),r;
	F0R(i,n) {cin >> l[i];}
	sort(l.begin(),l.end());
	while (l.back()>0) {r.pb(l.back()); l.pop_back();}
	r.pb(0); reverse(r.begin(),r.end());
	l.pb(0); reverse(l.begin(),l.end());

	auto chmin = [&](ll& a, ll b) {a = min(a,b);};
	auto left = [&](int i, int j)->ll {return (r.size()-j-1)+(l.size()-i-1);};
	vector<vector<vector<ll>>> dp(l.size(),vector<vector<ll>>(r.size(),vector<ll>(2,LLONG_MAX)));
	// on left/right, on cow i on left & cow j on right (1 indexed, inclusive)
	dp[0][0][0] = dp[0][0][1] = 0;
	F0R(i,l.size()) {
		F0R(j,r.size()) {
			F0R(k,2) {
				if (dp[i][j][k]==LLONG_MAX) {continue;}
				ll rem = left(i,j);
				if (i<l.size()-1) {
					if (k) {chmin(dp[i+1][j][0],dp[i][j][k]+(r[j]-l[i+1])*rem);}
					else {chmin(dp[i+1][j][0],dp[i][j][k]+(l[i]-l[i+1])*rem);}
				}
				if (j<r.size()-1) {
					if (k) {chmin(dp[i][j+1][1],dp[i][j][k]+(r[j+1]-r[j])*rem);}
					else {chmin(dp[i][j+1][1],dp[i][j][k]+(r[j+1]-l[i])*rem);}
				}
			}
		}
	} cout << min(dp[l.size()-1][r.size()-1][0],dp[l.size()-1][r.size()-1][1]) << '\n';
}