#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("skilevel.in","r",stdin);
	freopen("skilevel.out","w",stdout);
	
	int m, n, t, d; cin >> m >> n >> t;
	vector<vector<int>> a(m,vector<int>(n));

	vector<int> sp(m*n,0);
	vector<pii> add;
	F0R(i,m) {F0R(j,n) {cin >> a[i][j];}}
	F0R(i,m) {F0R(j,n) {cin >> d; sp[i*n+j]=d;}}

	F0R(i,m*n) {
		pii cur = {i/n,i%n};
		F0R(j,4) {
			pii x = {cur.f+dx[j],cur.s+dy[j]};
			if (x.f<0 || x.f>=m || x.s<0 || x.s>=n) {continue;}
			add.pb({i,x.f*n+x.s});
		}
	} 
	auto calc = [&](pii& x)->ll {return (ll)abs(a[x.f/n][x.f%n]-a[x.s/n][x.s%n]);};
	sort(add.begin(),add.end(),[&](pii& x, pii& y) {return calc(y)<calc(x);});
	
	vector<int> link(n*m), sz(n*m,1);
	F0R(i,n*m) {link[i]=i;}

	ll ans = 0;

	auto get = [&](auto& get, int x)->int {return (link[x]==x ? x : link[x]=get(get,link[x]));};
	auto unite = [&](int x, int y, ll dist)->bool {
		x = get(get,x), y = get(get,y);
		if (x != y) {
			if (sz[y]<sz[x]) {swap(x,y);}
			sz[y] += sz[x]; link[x] = y;
			sp[y] += sp[x];
			if (sz[y]>=t) {ans += dist*sp[y]; sp[y]=0;}
		} return false;
	};

	if (t>1) {
		while (add.size()) {
			pii x = add.back(); add.pop_back();
			unite(x.f,x.s,calc(x));
		} 
	} cout << ans << '\n';
}