#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m, k; cin >> m >> n >> k;
	v<v<int>> g(m,v<int>(n));
	F0R(i,m) {
		F0R(j,n) {
			cin >> g[i][j];
		}
	}

	ll ans = 0;

	auto doit = [&]() {
		v<v<ll>> ps(m+2,v<ll>(n+2,0));
		v<v<ll>> tl1=ps,tl2=ps,br1=ps,br2=ps;
		F0R(i,m) {
			F0R(j,n) {
				ps[i+1][j+1] = g[i][j]+ps[i][j+1]+ps[i+1][j]-ps[i][j];
			}
		}
		auto get = [&](int r1, int c1, int r2, int c2) {
			return ps[r2][c2]-ps[r2][c1-1]-ps[r1-1][c2]+ps[r1-1][c1-1];
		};

		FOR(i,k,m+1) {
			FOR(j,k,n+1) { // tr1 and br1 = max area covered by 1 square, tr2 & br2 are 2 squares
				ll a1 = get(i-k+1,j-k+1,i,j), a2 = get(m-i+1,n-j+1,m-i+k,n-j+k);
				chmax(tl1[i][j],max(a1,max(tl1[i-1][j],tl1[i][j-1])));
				chmax(br1[m-i+1][n-j+1],max(a2,max(br1[m-i+1][n-j+2],br1[m-i+2][n-j+1]))); // max of area and the previous dp values
 
				ll x = max(tl1[i-k][j],tl1[i][j-k]); // find max area for second square if you place a square here
				chmax(tl2[i][j],max(a1+x,max(tl2[i-1][j],tl2[i][j-1])));

				x = max(br1[m-i+k+1][n-j+1],br1[m-i+1][n-j+k+1]);
				chmax(br2[m-i+1][n-j+1],max(a2+x,max(br2[m-i+2][n-j+1],br2[m-i+1][n-j+2])));
			}
		}
		
		FOR(i,k,m-k+1) { // combine 1 and 2 square answers
			chmax(ans,max(tl1[i][n]+br2[i+1][1],tl2[i][n]+br1[i+1][1]));
		}
		FOR(i,k,n-k+1) {
			chmax(ans,max(tl1[m][i]+br2[1][i+1],tl2[m][i]+br1[1][i+1]));
		}
	};
	doit(); // top left & bottom right corners
	F0R(i,m) {reverse(g[i].begin(),g[i].end());}
	doit(); // bottom left & top right corners

	cout<<ans<<'\n';
}