#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	v<int> k(n);
	F0R(i,n) {cin >> k[i];}

	set<int> cur;
	int p2 = 0;
	int ans = 0;
	F0R(i,n) {
		while (p2<n && !cur.count(k[p2])) {cur.insert(k[p2++]);}
		chmax(ans,(int)cur.size());
		cur.erase(k[i]);
	} cout << ans << '\n';
}