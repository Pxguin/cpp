#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

v<pair<pii,int>> ts;
int n;
vector<pii> p;

int cross(pii& a, pii& b, pii& c) { // cross product ab and ac
	return (b.s-a.s)*(c.f-a.f)-(b.f-a.f)*(c.s-a.s);
}
bool o(pii& a, pii& b, pii& c) { // orientation
	return (cross(a,b,c)>0);
}
int area(pii& a, pii& b, pii& c) { // returns 2*area
	return abs(cross(a,b,c));
}
bool check(pii& a, pii& b, pii& c, pii& d) { // is d in Triangle(a,b,c)
	return (area(a,b,d)+area(a,c,d)+area(b,c,d))==area(a,b,c);
}
bool isect(pii& a, pii& b, pii& c, pii& d) { // does cd not intersect ab
	return (o(a,b,c)==o(a,b,d) || o(c,d,a)==o(c,d,b));
}
bool extend(pii& a, pii& b, pii& c, pii& d) { // can d extend Triangle(a,b,c)
	return !(check(a,b,c,d)) && (isect(a,b,c,d)&&isect(a,c,b,d)&&isect(b,c,a,d));
}

v<int> ret;
void nxt(int a, int b, int c, int d) {
	ret = {b,c,d};
	if (check(p[a],p[b],p[d],p[c])) {ret = {a,b,d};}
	else if (check(p[a],p[c],p[d],p[b])) {ret = {a,c,d};}
	sort(ret.begin(),ret.end()); 
}

int mod = 1e9+7;
void add(int& a, int b) {a = (a+b)%mod;}
int mul(int a, int b) {return (ll)a*b%mod;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n; p.resize(n);
	F0R(i,n) {cin >> p[i].f >> p[i].s;}
	v<v<v<v<int>>>> dp(n,v<v<v<int>>>(n,v<v<int>>(n,v<int>(n+1,0))));
	v<v<v<int>>> cnt(n,v<v<int>>(n,v<int>(n,3))); // amount of points in each triangle

	F0R(p1,n) {
		FOR(p2,p1+1,n) {
			FOR(p3,p2+1,n) {
				ts.pb({{p1,p2},p3});
				F0R(p4,n) {
					if (p4!=p1&&p4!=p2&&p4!=p3) {
						cnt[p1][p2][p3] += check(p[p1],p[p2],p[p3],p[p4]);
					}
				}
			}
		}
	}
	sort(ts.begin(),ts.end(),[&](pair<pii,int>& a, pair<pii,int>& b) {
		return area(p[a.f.f],p[a.f.s],p[a.s])<area(p[b.f.f],p[b.f.s],p[b.s]);
	});
	ll ans = 0;
	for (auto cur : ts) {
		int a = cur.f.f, b = cur.f.s, c = cur.s;
		dp[a][b][c][3] = 6;
		FOR(i,3,cnt[a][b][c]+1) {
			if (i<cnt[a][b][c]) {add(dp[a][b][c][i+1],mul(dp[a][b][c][i],cnt[a][b][c]-i));} // point inside
			F0R(d,n) {
				if (d!=a&&d!=b&&d!=c&&extend(p[a],p[b],p[c],p[d])) { // point outside
					nxt(a,b,c,d);
					add(dp[ret[0]][ret[1]][ret[2]][i+1],dp[a][b][c][i]);
				}
			}
		} ans = (ans+dp[a][b][c][n])%mod;
	} cout << ans << '\n';
} 