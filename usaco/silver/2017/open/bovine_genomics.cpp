#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("cownomics.in","r",stdin);
	freopen("cownomics.out","w",stdout);
	
	int n, m; cin >> n >> m;
	vector<string> spots(n), unspots(n);
	F0R(i,n) {cin >> spots[i];}
	F0R(i,n) {cin >> unspots[i];}
	bool mp[500] = {false};

	int ans = 0;
	vector<int> z(26); 
	z['A'-'A']=1; z['C'-'A']=2; z['G'-'A']=3; z['T'-'A']=4;
	auto hsh = [&](char a, char b, char c)->int {return (z[a-'A']+10*z[b-'A']+100*z[c-'A']);};
	auto doit = [&](int i, int j, int k, bool t)->void {
		F0R(x,n) {
			int s = hsh(spots[x][i],spots[x][j],spots[x][k]);
			mp[s] = t;
		}
	};

	F0R(i,m) {
		FOR(j,i+1,m) {
			FOR(k,j+1,m) {
				int flag = 0;
				doit(i,j,k,true);
				F0R(x,n) {
					int s = hsh(unspots[x][i],unspots[x][j],unspots[x][k]);
					flag |= (mp[s]);
				} doit(i,j,k,false);
				ans += !flag;
			}
		}
	} cout << ans << '\n';
}