#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<vector<int>> graph;
int n; 
vector<int> to_leaf;
int ans = 0;
int dist = 0, x = 0;

void sol1(int cur, int par) {
	vector<int> leaves;
	for (int adj : graph[cur]) {
		if (adj != par) {
			sol1(adj, cur);
			leaves.pb(to_leaf[adj]);
		}
	}
	sort(leaves.begin(), leaves.end());
	if (leaves.size()) {to_leaf[cur] = leaves.back()+1;}
	else {to_leaf[cur] = 0;}

	if (leaves.size() > 1) {
		ans = max(ans, max(to_leaf[cur], 2+leaves.back()+leaves[leaves.size()-2]));
	} else {ans = max(ans, to_leaf[cur]);}
}


void dfs(int cur, int par) {
	for (int adj : graph[cur]) {
		if (adj != par) {
			dist++;
			dfs(adj, cur);
		}
	}
	if (dist > ans) {x = cur; ans = dist;}
	dist--;

}
void sol2() {
	dfs(0, 0);
	ans = 0; dist = 0;
	dfs(x, x);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n; 
	graph.resize(n);
	to_leaf.assign(n, 0);
	int a, b;
	for (int i=0;i<n-1;i++) {
		cin >> a >> b; a--; b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	sol1(0,0);
	sol2();
	cout << ans << '\n';
}
