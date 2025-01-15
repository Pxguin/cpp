#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

struct Edge {
	int a, b, idx; ll c;
	Edge (int a1, int b1, ll c1, int i1) : a(a1), b(b1), c(c1), idx(i1) {};
	bool operator>(const Edge& y) {return c<y.c;}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n,m,k; cin >> n >> m >> k;
	int a1, b1; ll c1; vector<Edge> edges;

	F0R(i,m) {cin >> a1 >> b1 >> c1; edges.pb(Edge(--a1,--b1,c1,i));}
	sort(edges.begin(),edges.end(),greater<>());

	vector<vector<int>> par(k,vector<int>(n)), sz(k,vector<int>(n,1));
	F0R(i,k) {F0R(j,n) {par[i][j]=j;}}

	auto get = [&](auto&& get, int x, int z)->int{return (x==par[z][x] ? x : par[z][x] = get(get,par[z][x],z));};
	auto check = [&](int x, int y, int z) {return get(get,x,z)!=get(get,y,z);};
	auto unite = [&](int x, int y, int z) {
		int a1 = get(get,x,z), b1 = get(get,y,z);
		
		if (a1 != b1) {
			if (sz[z][a1] < sz[z][b1]) {swap(a1,b1);}
			sz[z][a1] += sz[z][b1];
			par[z][b1] = a1;
			return true;
		} return false;
	};

	vector<int> ans(m,0);
	while (edges.size()) {
		Edge cur = edges.back(); edges.pop_back();
		int l = 0, h = k-1, mid = (l+h)/2;
		int f = -1;
		while (l <= h) {
			if (check(cur.a,cur.b,mid)) {f = mid; h = mid-1;}
			else {l = mid+1;}
			mid = (l+h)/2;
		}
		if (f == -1) {ans[cur.idx]=0;}
		else {ans[cur.idx] = f+1; unite(cur.a,cur.b,f);}
	}
	for (int i : ans) {cout << i << '\n';}
}