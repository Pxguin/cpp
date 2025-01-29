#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

struct Edge {
	int a, b, w;
	Edge (int a1, int b1, int w1) : a(a1), b(b1), w(w1) {};
	bool const operator<(const Edge& y) {return w < y.w;}
};

int main() {
	freopen("superbull.in","r",stdin);
	freopen("superbull.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int v[n];
	for (int i=0;i<n;i++) {cin >> v[i];}

	vector<int> link, sz;
	vector<Edge> edges;
	for (int i=0;i<n;i++) {
		link.pb(i); sz.pb(1);
		for (int j=i+1;j<n;j++) {
			edges.pb(Edge(i, j, v[i]^v[j]));
		}
	}
	sort(edges.begin(), edges.end());
	
	auto find = [&](int x) {while (link[x] != x) {x = link[x];} return x;};
	auto unite = [&](int x, int y) {
		int a = find(x), b = find(y);
		if (a != b) {
			if (sz[a] < sz[b]) {swap(a,b);}
			sz[a] += sz[b];
			link[b] = a;
			return true;
		} return false;
	};

	ll ans = 0;
	while (edges.size()) {
		Edge x = edges.back(); edges.pop_back();
		if (unite(x.a, x.b)) {ans += x.w;}
	}
	cout << ans << '\n';
}
