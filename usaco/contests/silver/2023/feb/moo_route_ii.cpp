#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define mp make_pair

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	int r1, t1, r2, t2;

	int a[n];
	int ans[n];
	vector<pair<pii,int>> fs[n];

	for (int i=0;i<m;i++) {
		cin >> r1 >> t1 >> r2 >> t2; r1--; r2--;
		fs[r1].pb(mp(mp(t1,t2),r2));
	}
	for (int i=0;i<n;i++) {cin >> a[i];}
	for (int i=0;i<n;i++) {
		ans[i] = INT_MAX; 
		sort(fs[i].begin(), fs[i].end());
		for (pair<pii,int>& x : fs[i]) {x.f.s += a[x.s];}
	}
	ans[0] = 0;

	unordered_set<int> todo; todo.insert(0);
	while (todo.size()) {
		int x = *todo.begin();
		todo.erase(todo.begin());
		while (fs[x].size()) {
			auto& i = fs[x].back();
			if (i.f.f >= ans[x]) {
				if (i.f.s <= ans[i.s]) {
					ans[i.s] = i.f.s;
					if (fs[i.s].size() && ans[i.s]<=fs[i.s].back().f.f) {
						todo.insert(i.s);
					}
				}	
				fs[x].pop_back();
			} else {break;}
		}
	}
	a[0] = 0;
	for (int i=0;i<n;i++) {
		if (ans[i] == INT_MAX) {cout << -1;}
		else {cout << ans[i] - a[i];}
		cout << '\n';
	}

}
