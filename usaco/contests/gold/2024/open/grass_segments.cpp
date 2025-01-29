#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

struct Grass {
	int l, r, k, idx;
	Grass (int l, int r, int k, int idx) : l(l), r(r), k(k), idx(idx) {};
	bool operator<(const Grass& y) {return k < y.k;}
	bool operator>(const Grass& y) {return r-l < y.r-y.l;}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	int a,b,c;
	vector<Grass> g,g2;
	F0R(i,n) {
		cin >> a >> b >> c;
		g.pb(Grass(a,b,c,i));
		g2.pb(Grass(a,b,c,15000));
	}
	sort(g.begin(),g.end());
	sort(g2.begin(),g2.end(),greater<>());
	Tree<pii> setr, setl;
	vector<int> ans(n,0);

	while (g.size()) {
		Grass cur = g.back(); g.pop_back();
		while (g2.size() && g2.back().r-g2.back().l >= cur.k) {
			Grass x = g2.back(); g2.pop_back();
			setr.insert({x.r, setr.size()+1});
			setl.insert({x.l, setr.size()});
		}
		
		ans[cur.idx] = setr.order_of_key({cur.l+cur.k-1,INT_MAX}) + setl.size()-setl.order_of_key({cur.r-cur.k+1,-1});
		ans[cur.idx] = setr.size()-(cur.r-cur.l>=cur.k)-ans[cur.idx];
	}
	for (int i : ans) {cout << i << '\n';}
} 