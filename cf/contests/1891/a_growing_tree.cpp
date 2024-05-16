#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_N 500002
 
vector<pair<ll,int>> queries[MAX_N];
vector<int> tree[MAX_N];
int times[MAX_N];
ll bit[MAX_N] = {0};
int sz, q;
ll ans[MAX_N];
 
void update(int cur, ll val) {
	for (int i=cur; i<MAX_N; i+=(i&(-i))) {
		bit[i] += val;
	}
}
 
ll sum(int cur) {
	ll ret = 0;
	for (int i=cur; i>0; i-=(i&(-i))) {
		ret += bit[i];
	}
	return ret;
}
 
void dfs(int cur) {
	for (pair<ll,int> query : queries[cur]) {
		update(query.s, query.f);
	}
 
	// get ans
	ans[cur] = sum(q) - sum(times[cur]);
 
	// visit nodes
	for (int child : tree[cur]) {dfs(child);}
 
	for (pair<ll,int> query : queries[cur]) {
		update(query.s, -query.f);
	}
}
 
void solve() {
	cin >> q;
	for (int i=0;i<q+1;i++) {
		queries[i].clear();
		tree[i].clear();
	}
 
	int type, a;
	sz = 1;
	ll b;
	for (int i=0;i<q;i++) {
		cin >> type; 
		if (!(--type)) {
			cin >> a;
			sz++;
			tree[a].pb(sz);
			times[sz] = i+1;
		} else {
			cin >> a >> b;
			queries[a].pb(mp(b, i+1));
		}
	}
 
	dfs(1);
 
	for (int i=0;i<sz;i++) {
		cout << ans[i+1] << " ";
	}
	cout << "\n";
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	int t; cin >> t;
	while (t--) {solve();}
}