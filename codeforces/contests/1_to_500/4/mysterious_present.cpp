#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back

vector<pii> a;
vector<bool> vis;
vector<int> ts;
int n;

void dfs(int cur) {
	vis[cur] = true;
	for (int i=0;i<n;i++) {
		if (!vis[i] && (a[cur].f < a[i].f && a[cur].s < a[i].s)) {dfs(i);}
	}
	ts.pb(cur);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int w, h; cin >> n >> w >> h;
	a.resize(n+1); vis.assign(n+1, false);
	for (int i=0;i<n;i++) {cin >> a[i].f >> a[i].s;}
	a[n] = mp(w,h);
	dfs(n);
	reverse(ts.begin(), ts.end());

	vector<int> dist(n+1, 0), par(n+1, -1);
	for (int i : ts) {
		for (int j=0;j<n;j++) {
			if (a[i].f < a[j].f && a[i].s < a[j].s) {
				if (dist[j] < dist[i]+1) {par[j] = i; dist[j] = dist[i]+1;}
			}
		}
	} pii mx = {0,0};
	for (int i=0;i<n;i++) {if (dist[i] > mx.f) {mx.f = dist[i]; mx.s = i;}}
	if (!mx.f) {cout << 0 << '\n';}
	else {
		vector<int> ans; ans.pb(mx.s);
		while (par[ans.back()] != n) {ans.pb(par[ans.back()]);}
		cout << ans.size() << '\n'; 
		while (ans.size()) {cout << ans.back()+1 << ' '; ans.pop_back();}
	}

}
