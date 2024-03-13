#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q;
	int c[n], t;
	int queries[1000001] = {0};
	for (int i=0;i<n;i++) {cin >> c[i];}
	for (int i=0;i<n;i++) {
		cin >> t;
		if (t < c[i]) {queries[0]++; queries[c[i]-t]++;}
	}
	for (int i=1;i<=1000001;i++) {queries[i] = queries[i-1]-queries[i];}

	while (q--) {
		int s, v; cin >> v >> s;
		cout << (queries[s] >= v ? "YES" : "NO") << "\n";
	}
}