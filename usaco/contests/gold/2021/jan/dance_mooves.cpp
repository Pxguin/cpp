#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, a, b; ll m, k; cin >> n >> k >> m;
	vector<unordered_set<int>> shift(n);
	vector<unordered_set<int>> path(n);
	vector<int> pos(n);
	vector<pii> swaps(k);
	F0R(i,n) {pos[i]=i; shift[i].insert(i);}
	int rem = m%k; m -= rem;

	F0R(i,k) {
		cin >> a >> b; a--; b--;
		swaps[i] = {a,b};
	}
	F0R(i,k) { // build functional graph
		pii cur = swaps[(i+rem)%k];
		swap(pos[cur.f],pos[cur.s]);
		path[pos[cur.f]].insert(cur.f); path[pos[cur.s]].insert(cur.s);
	}
	vector<int> to(n);
	F0R(i,n) {to[pos[i]] = i;}

	F0R(i,n) {pos[i]=i;}
	F0R(i,rem) { // find starting positions for each cow
		pii cur = swaps[i];
		swap(pos[cur.f],pos[cur.s]);
		shift[pos[cur.f]].insert(cur.f); shift[pos[cur.s]].insert(cur.s);
	}
	vector<int> freq(n,0);
	vector<bool> vis(n,false);
	vector<int> ans(n);
	int cnt = 0;

	auto add = [&](unordered_set<int>& x) {for (int i : x) {cnt += (++freq[i]==1);}};
	auto del = [&](unordered_set<int>& x) {for (int i : x) {cnt -= (--freq[i]==0);}};
	auto calc = [&](int x) {
		add(shift[x]);
		ans[x] = cnt;
		del(shift[x]);
	};
	if (m) {
		F0R(i,n) {
			if (!vis[i]) {
				vector<int> cyc; // cycle finding
				int cur = i;
				while (!vis[cur]) {
					vis[cur] = true;
					cyc.pb(cur);
					cur = to[cur];
				} int L = min((ll)cyc.size(),m/k);

				F0R(j,L) {add(path[cyc[j]]);} // first node
				calc(pos[cyc[0]]);

				FOR(j,1,cyc.size()) { // all other nodes
					del(path[cyc[j-1]]);
					add(path[cyc[(j+L-1)%cyc.size()]]);
					calc(pos[cyc[j]]);
				} del(path[cyc.back()]);
				F0R(j,L-1) {del(path[cyc[j]]);} // clear array
			}
		}
	} else {F0R(i,n) {ans[i]=shift[i].size();}}
	for (int x : ans) {cout << x << '\n';}
}
