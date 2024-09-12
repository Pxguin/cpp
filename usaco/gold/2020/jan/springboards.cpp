#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("boards.in","r",stdin);
	freopen("boards.out","w",stdout);

	int n, p; cin >> n >> p;
	map<int,int> m;
	vector<pair<pii,pii>> boards(p);
	vector<pair<pii,int>> a;
	vector<int> dist(p+1,INT_MAX);
	F0R(i,p) {
		cin >> boards[i].f.f >> boards[i].f.s >> boards[i].s.f >> boards[i].s.s;
		if (boards[i].f==boards[i].s) {continue;}
		a.pb({boards[i].f,i+1}); a.pb({boards[i].s,-(i+1)});
	}
	
	auto add = [&](int i, int d) {
		auto it = --(m.upper_bound(i));
		if (it->s <= d) {return;}
		it = m.insert(it,{i,d}); it->s = d;
		while (it!=(--m.end()) && next(it)->s >= d) {m.erase(next(it));}
	};
	auto get = [&](int i) {
		auto it = --m.upper_bound(i);
		return ((it->f<=i) ? it->s : 0);
	};
	
	m[0] = 0; a.pb({{n,n},p+1});
	sort(a.begin(),a.end());
	for (pair<pii,int> cur : a) {
		if (cur.s < 0) {add(cur.f.s,dist[-(++cur.s)]-cur.f.f-cur.f.s);} 
		else {dist[--cur.s] = cur.f.f+cur.f.s+get(cur.f.s);}
	} cout << dist[p] << '\n';
}