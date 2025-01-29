#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

struct Edge {
	int a, b;
	ll sz;
	Edge(int a1, int b1, ll sz1) : a(a1), b(b1), sz(sz1) {};
	bool operator<(const Edge& y) const {return y.sz < sz;}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	int link[n], size[n];
	vector<Edge> edges;
	int a; ll b;
	for (int i=0;i<n;i++) {
		link[i] = i; size[i] = 1;

		cin >> a >> b; a--;
		edges.pb(Edge(i, a, b));
	}

	sort(edges.begin(), edges.end());
	ll ans = 0;

	auto find = [&](int x) {
		while (link[x] != x) {x = link[x];}
		return x;
	};

	for (Edge& e : edges) {
		int c1 = find(e.a); int c2 = find(e.b);
		if (c1 != c2) {
			if (size[c1] < size[c2]) {swap(c1, c2);}
			size[c1] += size[c2];
			link[c2] = c1;
			ans += e.sz;
		}
	}
	
	cout << ans << '\n';
}
