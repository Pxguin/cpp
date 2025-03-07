#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
 
void dfs(int cur, vector<vector<int>>& debt, vector<bool>& vis) {
	vis[cur] = true;
	for (int i : debt[cur]) {
		if (!vis[i]) {dfs(i, debt, vis);}
	}
	cout << cur+1 << " ";
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	
	int a, b;
	vector<vector<int>> debt(n);
	for (int i=0;i<m;i++) {
		cin >> a >> b; a--; b--;
		debt[a].pb(b);
	}
 
	vector<bool> vis(n, false);
 
	for (int i=0;i<n;i++) {
		if (!vis[i]) {
			dfs(i, debt, vis);
		}
	}
}