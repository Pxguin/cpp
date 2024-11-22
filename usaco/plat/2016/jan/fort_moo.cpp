#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("fortmoo.in","r",stdin);
	freopen("fortmoo.out","w",stdout);

	int n, m; cin >> n >> m;
	char c;
	v<v<int>> g(n,v<int>(m));
	v<v<int>> ps(n+1,v<int>(m+1,0));
	F0R(i,n) {
		F0R(j,m) {
			cin >> c;
			g[i][j] = (c=='X');
			ps[i+1][j+1] = g[i][j]+ps[i][j+1]+ps[i+1][j]-ps[i][j];
		}
	}
	auto get = [&](int r1, int c1, int r2, int c2) {
		return (ps[r2+1][c2+1]-ps[r1][c2+1]-ps[r2+1][c1]+ps[r1][c1]);
	};

	int ans = 0;
	FOR(h,1,n+1) { // height
		F0R(r,n-h+1) { // row
			F0R(start,m) { // start point
				if (get(r,start,r+h-1,start)==0) {
					int ptr = start;
					while (ptr<m && g[r][ptr]+g[r+h-1][ptr]==0) { // continue while top and bottom are empty
						if (!get(r,ptr,r+h-1,ptr)) {chmax(ans,(ptr-start+1)*h);} // update answer if valid right boundary
						ptr++;
					}
					start = ptr; // update initial pointer
				}
			}
		}
	} cout << ans << '\n';
}