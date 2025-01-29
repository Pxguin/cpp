#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

struct Rect {
	int top = 10000, left = 10000, right = -1, bottom = -1;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("art.in","r",stdin);
	freopen("art.out","w",stdout);
	
	int n; cin >> n;
	int c;
	vector<Rect> r(n*n);
	vector<vector<int>> col(n+1,vector<int>(n+1));
	F0R(i,n) {
		F0R(j,n) {
			cin >> c; c--;
			col[i+1][j+1]=c;
			if (c>=0) {
				chmin(r[c].top,i+1); chmax(r[c].bottom,i+1);
				chmin(r[c].left,j+1); chmax(r[c].right,j+1);
			}
		}
	}
	vector<vector<int>> ps(n+2,vector<int>(n+2,0));
	int numberofvalidrectangles = 0; // for the side case
	F0R(i,n*n) {
		Rect cur = r[i];
		if (cur.top!=10000) {
			numberofvalidrectangles++;
			ps[cur.top][cur.left]++;
			ps[cur.bottom+1][cur.right+1]++;
			ps[cur.top][cur.right+1]--;
			ps[cur.bottom+1][cur.left]--;
		}
	}
	vector<bool> ok(n*n,true);
	FOR(i,1,n+1) {
		FOR(j,1,n+1) {
			ps[i][j] += ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1];
			if (ps[i][j]>1) {ok[col[i][j]]=false;}
		}
	}
	int ans = 0;
	F0R(i,n*n) {ans += ok[i];}
	if (numberofvalidrectangles==1&&n!=1) {ans--;} // side case: only 1 visible painted rectangle
	cout << ans << '\n';
}