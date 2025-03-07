#include <bits/stdc++.h>
using namespace std;


#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m, k; cin >> n >> m >> k;
	char c;
	int s = 0, sz;
	vector<vector<int>> grid(n,vector<int>(m,0));
	vector<vector<bool>> vis(n,vector<bool>(m,false));
	
	F0R(i,n) {
	    F0R(j,m) {
	        cin >> c;
	        grid[i][j] = (c=='#');
			s += (c=='.');
	    }
	}

	bool flag = false;
	int cn = 2;
	auto ff = [&](auto& ff, int i, int j)->void {
	    if (i<0||i>=n||j<0||j>=m) {return;}
	    if (grid[i][j]==1||vis[i][j]||flag) {return;}
		vis[i][j] = true;
		if (++sz==s-k) {flag = true;}
		grid[i][j] = c;
	
		ff(ff,i+1,j); ff(ff,i-1,j);
		ff(ff,i,j+1); ff(ff,i,j-1);
	};
	F0R(i,n) {
		F0R(j,m) {
			if (!vis[i][j]) {
				if (flag) {continue;}
				sz = 0; c++;
				ff(ff,i,j);
			}
		}
	}
	F0R(i,n) {
		F0R(j,m) {
			if (grid[i][j]==1) {cout<<'#';}
			else if (grid[i][j]==c) {cout<<'.';}
			else {cout<<'X';}
		} cout << '\n';
	}
}