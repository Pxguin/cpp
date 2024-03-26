#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define pb push_back

bool solve() {
	int n; cin >> n;
	map<int,vector<int>> ranges;
	
	for (int i=0;i<n;i++) {
		int l, r; cin >> l >> r;
		ranges[l].pb(r);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i=ranges.begin()->f;i<=1e9;i++) {
		if (ranges.count(i)) {for (int j : ranges[i]) {pq.push(j);}}
		if (pq.top() < i) {return false;}
		pq.pop();
		if (pq.empty()) {
			auto it = ranges.upper_bound(i);
			if (it == ranges.end()) {return true;}
			else {i = it->f-1;}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {cout << (solve() ? "Yes" : "No") << '\n';}
}
