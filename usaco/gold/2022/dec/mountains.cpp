#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<double,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, q, t, h; cin >> n;
	int a[n];
	vector<vector<double>> slope(n,vector<double>(n));
	vector<set<pii>> seq(n);

	auto calc = [&](int i)->void {
		seq[i].clear(); seq[i].insert({-1e10,-1});
		FOR(j,i+1,n) {
			slope[i][j] = (double)(a[j]-a[i])/(j-i);
			if (slope[i][j]>=seq[i].rbegin()->f) {seq[i].insert({slope[i][j],j});}
		}
		seq[i].insert({1e10,99999});
	};

	F0R(i,n) {cin >> a[i];}
	F0R(i,n) {calc(i);}

	cin >> q;
	while (q--) {
		cin >> t >> h; t--;
		a[t] += h;
		calc(t); // recalculate array t
		F0R(i,t) {
			if (seq[i].count({slope[i][t],t})) {seq[i].erase({slope[i][t],t});} // remove prev
			slope[i][t] = (double)(a[t]-a[i])/(t-i);
			auto it = seq[i].insert({slope[i][t],t}).f;
			if (next(it)->s < t) {seq[i].erase({slope[i][t],t});}
			else {
				while (prev(it)->s > t) {seq[i].erase(prev(it));}
			}
		}

		int ans = 0;
		F0R(i,n) {ans += seq[i].size()-2;} 
		cout << ans << '\n';
	}
} 