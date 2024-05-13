#include <bits/stdc++.h>
using namespace std;

struct Fountain {
	int b, p, idx;
	Fountain(int b1, int p1, int idx1) : b(b1), p(p1), idx(idx1) {};
	bool operator<(const Fountain& y) {return p < y.p;}
};

#define pb push_back
#define mp make_pair
#define ppii pair<pair<int,int>,int>
#define f first
#define s second

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int c[2];
	int n; cin >> n >> c[0] >> c[1];
	int b1, p1;
	char t;

	vector<Fountain> f[2];
	vector<Fountain> init[2];
	for (int i=0;i<n;i++) {
		cin >> b1 >> p1 >> t;
		f[t == 'D'].pb(Fountain(b1, p1, i));
		init[t == 'D'].pb(Fountain(b1, p1, i));
		// 0 : coins // 1 : diamonds
	}
	for (int i=0;i<2;i++) {
		sort(f[i].begin(), f[i].end());
		sort(init[i].begin(), init[i].end());
	}
	vector<ppii> mx[2];
	for (int i=0;i<2;i++) {
		int mx1 = 0, mx2 = 0, index = 0;
		for (Fountain x : f[i]) {
			if (x.b >= mx1) {
				mx2 = mx1;
				mx1 = x.b; index = x.idx;
			} else if (x.b > mx2) {mx2 = x.b;}
			mx[i].pb(mp(mp(mx1,index),mx2));
		}
	}

	int ok[2] = {0};
	for (int i=0;i<2;i++) {
		for (int j=0;j<f[i].size();j++) {
			if (f[i][j].p <= c[i]) {ok[i] = max(ok[i], f[i][j].b);}
		}
	}
	int ans = ((ok[0] && ok[1]) ? ok[0]+ok[1] : 0);
	for (int i=0;i<2;i++) {
		for (int j=0;j<init[i].size();j++) {
			while (f[i].size() && init[i][j].p+f[i].back().p > c[i]) {f[i].pop_back();}
			if (f[i].size() > 1) {
				int z = f[i].size()-1;
				ans = max(ans, ((init[i][j].idx == mx[i][z].f.s) ? mx[i][z].s : mx[i][z].f.f)+init[i][j].b);
			}
		}
	}
	cout << ans << '\n';
}
