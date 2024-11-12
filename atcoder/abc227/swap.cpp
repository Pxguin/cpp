#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define chmin(a, b) a = min(a, b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	string s; cin >> s;
	int ub, n; cin >> ub;
	n = s.size();
	chmin(ub,n*(n+1)/2);
	v<int> ps_k(n+1,0),ps_e(n+1,0),ps_y(n+1,0);
	v<int> k={0},e={0},y={0};
	F0R(i,n) {
		ps_k[i+1] = ps_k[i]+(s[i]=='K');
		ps_e[i+1] = ps_e[i]+(s[i]=='E');
		ps_y[i+1] = ps_y[i]+(s[i]=='Y');

		if (s[i]=='K') {k.pb(i+1);}
		else if (s[i]=='E') {e.pb(i+1);}
		else {y.pb(i+1);}
	}

	ll dp[466][32][32][32] = {0};
	dp[0][0][0][0] = 1;
	
	F0R(op,ub+1) {
		F0R(a,k.size()) {
			F0R(b,e.size()) {
				F0R(c,y.size()) {
					if (a!=k.size()) {
						int add = max(0,ps_e[k[a+1]]-b)+max(0,ps_y[k[a+1]]-c);
						if (op+add<=ub) {dp[op+add][a+1][b][c] += dp[op][a][b][c];}
					}
					if (b!=e.size()) {
						int add = max(0,ps_k[e[b+1]]-a)+max(0,ps_y[e[b+1]]-c);
						if (op+add<=ub) {dp[op+add][a][b+1][c] += dp[op][a][b][c];}
					}
					if (c!=y.size()) {
						int add = max(0,ps_k[y[c+1]]-a)+max(0,ps_e[y[c+1]]-b);
						if (op+add<=ub) {dp[op+add][a][b][c+1] += dp[op][a][b][c];}
					}
				}
			}
		}
	} 

	ll ans = 0;
	F0R(i,ub+1) {ans += dp[i][k.size()-1][e.size()-1][y.size()-1];}
	cout << ans << '\n';
}