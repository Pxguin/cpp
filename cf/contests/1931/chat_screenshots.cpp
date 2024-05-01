#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<vector<int>> adj;
vector<bool> vis;
vector<bool> used;
bool flag;

void dfs(int cur) {
	vis[cur] = true;
	used[cur] = true;
	for (int x : adj[cur]) {
		if (!vis[x]) {dfs(x);}
		else {flag = (flag || used[x]);}
	}
	used[cur] = false;
}

void solve() {
	int n, k; cin >> n >> k;
	int a,b;
	adj = vector<vector<int>>(n);
	vis = vector<bool>(n);
	used = vector<bool>(n);
	flag = false;

	for (int i=0;i<k;i++) {
		cin >> a; 
		if (n > 1) {cin >> a; a--;}
		for (int j=0;j<n-2;j++) {
			cin >> b; b--;
			adj[a].pb(b);
			a = b;
		}
	}

	for (int i=0;i<n;i++) {
		if (!vis[i]) {dfs(i);}
		if (flag) {break;}
	}
	cout << (flag ? "NO" : "YES") << '\n';
}

int main() {
	int t; cin >> t;
	while (t--) {solve();}
}
