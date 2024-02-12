#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
bool visit_bool = false;
vector<int> clocks;

int dfs(int node) {
	visited[node] = visit_bool;
	int sum = clocks[node];

	for (int i : tree[node]) {
		if (visited[i] != visit_bool) {
			sum -= dfs(i);
		}
	}
	return sum;
}

int main() {
	freopen("clocktree.in","r",stdin); freopen("clocktree.out","w",stdout);
	int n; cin >> n;
	int a, b;
	tree.resize(n); clocks.resize(n);
	visited.resize(n);
	for (int i=0;i<n;i++) {cin >> clocks[i];}
	for (int i=0;i<n-1;i++) {
		cin >> a >> b; a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	int ans = 0;

	fill(visited.begin(),visited.end(),visit_bool);
	for (int i=0;i<n;i++) {
		visit_bool = !visit_bool;
		int sum = dfs(i);
		if ((sum % 12 + 12) % 12 / 2 == 0) {
			ans++;
		}
	}
	cout << ans;

}
