#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

struct Edge {
	int u, v, b; ld a;
	Edge (int u1, int v1, ld a1, int b1) : u(u1), v(v1), a(a1), b(b1) {};
	bool operator<(const Edge& y) {return a < y.a;}
};

vector<Edge> e;
int n;
ll ans1=0,ans2=0,cur1,cur2;

bool check(ld m) {
	cur1 = cur2 = 0;
	vector<Edge> edges;
	F0R(i,e.size()) {edges.pb(Edge(e[i].u,e[i].v,(ld)e[i].a-m*(ld)e[i].b,i));}
	sort(edges.begin(),edges.end());
	
	vector<int> link(n), sz(n,1);
	F0R(i,n) {link[i] = i;}
	auto get = [&](int x) {while (link[x] != x) {x = link[x];} return x;};
	auto unite = [&](int x, int y) {
		int a = get(x), b = get(y);
		if (a != b) {
			if (sz[a] > sz[b]) {swap(a,b);}
			link[a] = b; sz[b] += sz[a];
			return true;
		} return false;
	};
	ld sum = 0;
	while (edges.size()) {
		Edge x = edges.back(); edges.pop_back();
		if (unite(x.u,x.v)) {cur1 += e[x.b].a; cur2 += e[x.b].b; sum += x.a;}
	} 
	return (sum >= 0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int m; cin >> n >> m;
	int u1, v1, a1, b1;
	F0R(i,m) {
		cin >> u1 >> v1 >> a1 >> b1;
		if (u1^v1) {e.pb(Edge(u1,v1,a1,b1));}
	}
	ld l = 0, h = 1e7, mid = (l+h)/2;
	F0R(i,100) {
		if (check(mid)) {
			l = mid;
			ans1 = cur1; ans2 = cur2;
		} else {h = mid;}
		mid = (l+h)/2;
	} 
	ll g = gcd(ans1,ans2);
	cout << (ans1/g) << '/' << (ans2/g) << '\n';
}
