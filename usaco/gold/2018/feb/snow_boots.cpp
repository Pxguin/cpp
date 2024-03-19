#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second

struct Boot {
	int s1, d, i;
	bool operator <(const Boot& y) {return s1 > y.s1;}
};

int main() {
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, b; cin >> n >> b;
	vector<pair<int,int>> tiles(n);

	for (int i=0;i<n;i++) {cin >> tiles[i].f; tiles[i].s = i;}
	tiles[n-1].s = 0;
	sort(tiles.begin(), tiles.end());
	Boot b1;
	vector<Boot> boots;

	for (int i=0;i<b;i++) {
		cin >> b1.s1 >> b1.d; b1.i = i;
		boots.pb(b1);
	}
	sort(boots.begin(), boots.end());
	bool ans[b];

	int mx[n]; mx[0] = 0; if (n != 1) {mx[1] = n-1;} 
	set<int> cur; cur.insert(0); cur.insert(n-1);
	multiset<int> q; q.insert(n-1);
	for (int i=2;i<n;i++) {
		cur.insert(tiles[i].s);
		auto idx = cur.find(tiles[i].s);
		int val = *next(idx)-*prev(idx);
		q.erase(q.find(val));
		q.insert(*next(idx)-*idx);
		q.insert(*idx-*prev(idx));
		mx[i] = *(--q.end());
	}

	for (const Boot& x : boots) {
		while (tiles.back().f > x.s1) {tiles.pop_back();}
		ans[x.i] = mx[tiles.size()-1] <= x.d;
	}
	for (bool i : ans) {cout << i << "\n";}
}
