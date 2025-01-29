#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

struct Edge {
	int a, b, c;
	Edge (int a1, int b1, int c1) : a(a1),b(b1),c(c1) {};
	bool operator>(const Edge& y) const {return c > y.c;}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	int cost, a1, b1, c1, d1;
	vector<Edge> edges;
	F0R(i,n) {
		cin >> cost >> a1 >> b1 >> c1 >> d1;
		edges.pb(Edge(--a1,--b1,0)); edges.pb(Edge(--c1,--d1,0));
		edges.pb(Edge(a1,c1,cost));
	} sort(edges.begin(),edges.end(),greater<Edge>());
	int ans = 0;

	vector<int> link(2*n), sz(2*n,1);
	F0R(i,2*n) {link[i]=i;}

	auto get = [&](int x) {while (link[x]!=x) {x=link[x];} return x;};
	auto unite = [&](int x, int y) {
		int x1 = get(x), y1 = get(y);
		if (x1 != y1) {
			if (sz[x1]>sz[y1]) {swap(x1,y1);}
			link[x1] = y1; sz[y1] += x1;
			return true;
		} return false;
	};

	while (edges.size()) {
		if (unite(edges.back().a,edges.back().b)) {ans += edges.back().c;}
		edges.pop_back();
	} cout << ans << '\n';
}