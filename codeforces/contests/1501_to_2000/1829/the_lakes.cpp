#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define chmax(a, b) a = max(a,b)

void solve() {
	int n, m;
	vector<vector<int>> depth;
	vector<vector<bool>> vis;
	int cand = 0;

	cin >> n >> m;
	depth = vector<vector<int>>(n,vector<int>(m));
	vis = vector<vector<bool>>(n,vector<bool>(m,false));
	F0R(i,n) {
		F0R(j,m) {cin >> depth[i][j];}
	}
	int ans = 0;

	auto ff = [&](auto& ff, int row, int col)->void {
		if (row<0||row>=n||col<0||col>=m) {return;}
		if (!depth[row][col]||vis[row][col]) {return;}
		vis[row][col] = (cand+=depth[row][col]);
		ff(ff,row+1,col);
		ff(ff,row-1,col);
		ff(ff,row,col+1);
		ff(ff,row,col-1);
	};

	F0R(i,n) {
		F0R(j,m) {
			if (!vis[i][j] && depth[i][j]) {
				cand = 0;
				ff(ff,i,j);
				chmax(ans,cand);
			}
		}
	} cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}