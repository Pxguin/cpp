#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n];
	vector<int> ans(n,-1), from(n,-1);
	unordered_set<int> left, vis;
	for (int i=0;i<n;i++) {
		cin >> a[i]; a[i]--; 
		left.insert(i); vis.insert(i);
	}
	int k=0;
	for (int i=0;i<n;i++) {
		if (vis.count(a[i])) {
			left.erase(i); vis.erase(a[i]);
			ans[i] = a[i]; from[a[i]] = i;
			k++;
		}
	}
	while (left.size()) {
		int x = *left.begin(); left.erase(x);
		int y = *vis.begin(); vis.erase(y);
		if (x == y) {
			ans[x] = a[x];
			ans[from[a[x]]] = x;
			from[x] = from[a[x]];
			from[a[x]] = x;
		}
		else {ans[x] = y;}
	}
	cout << k << '\n';
	for (int i : ans) {cout << i+1 << ' ';} cout << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}
