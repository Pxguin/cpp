#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)
 
struct Edge {
	int u,v; ll w;
	Edge (int u, int v, ll w) : u(u),v(v),w(w) {};
	bool operator>(Edge& y) {return w > y.w;}
};
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	F0R(i,n) {cin >> a[i];}
	sort(a.begin(),a.end(),greater<int>());
	a.resize(distance(a.begin(),unique(a.begin(),a.end())));
	n = a.size();
 
	vector<int> ptr(10000002,INT_MAX-1);
	unordered_map<int,int> rev;
	vector<Edge> e;
	F0R(i,n) {ptr[a[i]]=0; rev[a[i]]=i;}
	for (int i=ptr.size()-2;i>=0;i--) {ptr[i] = min(ptr[i],ptr[i+1]+1);}
 
	F0R(i,n) {
		int x = a[i];
		if (ptr[x+1]!=INT_MAX-1) {e.pb(Edge(i,rev[x+1+ptr[x+1]],(x+1+ptr[x+1])%x));}
		int last = (ptr[x+1]!=INT_MAX-1 ? x+1+ptr[x+1] : -1);
		FOR(j,x*2,1e7+2,x) {
			if (ptr[j]==INT_MAX-1) {break;}
			if (j+ptr[j]==last) {e.pop_back();}
			e.pb(Edge(i,rev[j+ptr[j]],(j+ptr[j])%j));
			last = j+ptr[j];
		}
	}
 
	vector<int> par(n),sz(n,1);
	F0R(i,n) {par[i]=i;}
	auto get = [&](auto& get, int x)->int {return (par[x]==x ? x : par[x]=get(get,par[x]));};
	auto unite = [&](int x, int y)->bool {
		x = get(get,x), y = get(get,y);
		if (x != y) {
			if (sz[y]<sz[x]) {swap(x,y);}
			sz[y] += sz[y]; par[x] = y;
			return true;
		} return false;
	};
 
	sort(e.begin(),e.end(),greater<>());
	ll ans = 0;
	while (e.size()) {
		Edge x = e.back();
		if (unite(x.u,x.v)) {ans += x.w;}
		e.pop_back();
	} cout << ans << '\n';
}