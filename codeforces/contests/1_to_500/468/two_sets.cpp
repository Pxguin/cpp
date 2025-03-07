#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; ll a, b; cin >> n >> a >> b;
	int x;
	if (a == b) {b = LLONG_MAX;}
	unordered_map<int,int> idx;
	vector<int> adj(n,n),adj2(n,n);
	for (int i=0;i<n;i++) {
		cin >> x; idx[x] = i;
		if (idx.count(a-x)) {adj[i]=idx[a-x]; adj[idx[a-x]]=i;}
		if (idx.count(b-x)) {adj2[i]=idx[b-x]; adj2[idx[b-x]]=i;}
	}
	vector<int> ans(n,-1); vector<int> c(n+1,0); c[n] = 100;
	queue<int> q;
	for (int i=0;i<n;i++) {
		c[adj[i]]++; c[adj2[i]]++;
	}
	for (int i=0;i<n;i++) {if (c[i] == 1) {q.push(i);}}
	int ok = 0;
	auto f = [&](int& cur, bool x1, vector<int>& ptr, vector<int>& p2) {
		// group cur & nxt together
		int nxt = ptr[cur];
		ok += -(nxt==cur)+2;
		ans[cur] = ans[nxt] = x1;
		for (int i=0;i<2;i++) {
			if (p2[nxt] != n) {
				p2[p2[nxt]] = n; 
				if (p2[nxt] == n) {continue;}
				c[p2[nxt]]--; 
				if (c[p2[nxt]] == 1) {q.push(p2[nxt]);}
			}
			swap(cur,nxt);
		}
		c[cur] = c[nxt] = 0;
		adj[cur] = adj[nxt] = adj2[cur] = adj2[nxt] = n;
	};
	while (q.size()) {
		int cur = q.front(); q.pop();
		if (adj[cur] != n) {f(cur, false, adj, adj2);}
		else if (adj2[cur] != n) {f(cur, true, adj2, adj);}
	}
	if (ok == n) {
		cout << "YES" << '\n';
		for (int i : ans) {cout << i << ' ';}
	} else {cout << "NO";}
}
