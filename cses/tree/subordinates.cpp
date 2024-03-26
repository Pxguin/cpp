#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<vector<int>> graph;
vector<int> ans;

int dfs(int cur, int par) {
	for (int adj : graph[cur]) {
		if (adj != par) {
			ans[cur] += dfs(adj, cur);
		}
	}
	return ans[cur]+1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, a; cin >> n;
	graph.resize(n);
	ans.assign(n, 0);
	for (int i=0;i<n-1;i++) {
		cin >> a; a--;
		graph[a].pb(i+1);
		graph[i+1].pb(a);
	}

	dfs(0,0);

	for (int i : ans) {cout << i << ' ';}
	
}
