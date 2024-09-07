#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
	freopen("closing.in","r",stdin);
	freopen("closing.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	int a, b;
	vector<vector<int>> edges(n);
	stack<int> close;
	int link[n], sz[n];
	for (int i=0;i<m;i++) {
		cin >> a >> b; a--; b--;
		edges[a].pb(b); edges[b].pb(a);
	}

	stack<bool> ans;
	for (int i=0;i<n;i++) {
		cin >> a; a--;
		close.push(a);
		link[i] = i; sz[i] = 1;
	}

	auto find = [&](int x) {
		while (link[x] != x) {x = link[x];}
		return x;
	};
	auto unite = [&](int x, int y) {
		int c1 = find(x), c2 = find(y);
		if (c1 != c2) {
			if (sz[c1] > sz[c2]) {swap(c1,c2);}
			sz[c2] += sz[c1];
			link[c1] = c2;
			return true;
		}
		return false;
	};
	int components = 0;
	vector<bool> ok(n,false);
	
	while (close.size()) {
		a = close.top(); close.pop();
		components++; ok[a] = true;
		for (int i : edges[a]) {
			if (ok[i]) {
				if (unite(a,i)) {components--;}
			}
		}
		ans.push(components == 1);
	}
	while (ans.size()) {
		cout << (ans.top() ? "YES" : "NO") << '\n';
		ans.pop();
	}
}
