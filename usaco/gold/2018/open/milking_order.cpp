#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int> ans, ts;
vector<vector<int>> rules;
vector<int> vis, used;
bool flag;
int n, m, x, a, b; 

bool check(int mid) {
	vector<vector<int>> adj(n);
	for (int i=0;i<n;i++) {vis[i] = false;}
	flag = false;
	for (int i=0;i<mid;i++) {
		if (rules[i][0] > 1) {
			for (int j=2;j<=rules[i][0];j++) {
				adj[rules[i][j-1]-1].pb(rules[i][j]-1);
			}
		}
	}

	vector<int> indegree(n,0);
	for (int i=0;i<n;i++) {
		for (int j : adj[i]) {indegree[j]++;}
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i=0;i<n;i++) {if (indegree[i] == 0) {pq.push(i);}}
	
	while (pq.size()) {
		int cur = pq.top(); pq.pop();
		ts.pb(cur);
		for (int nxt : adj[cur]) {
			if (!(--indegree[nxt])) {pq.push(nxt);}
		}
	}
	return (ts.size() == n);
}

int main() {
	freopen("milkorder.in","r",stdin);
	freopen("milkorder.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	rules.resize(m); vis.resize(n); used.resize(n);
	for (int i=0;i<m;i++) {
		cin >> x;
		rules[i].pb(x);
		while (x--) {
			cin >> a; rules[i].pb(a);
		}
	}

	int l = 0, h = m, mid = (l+h)/2;
	while (l <= h) {
		ts.clear();
		if (check(mid)) {
			l = mid+1; ans = ts; 
		} else {h = mid-1;}
		mid = (l+h)/2;
	} 
	cout << ans[0]+1;
	for (int i=1;i<ans.size();i++) {cout << ' ' << ans[i]+1;}
}

