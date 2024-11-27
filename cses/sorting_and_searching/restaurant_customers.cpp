#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, a, b; cin >> n;
	v<int> start, stop;
	F0R(i,n) {
		cin >> a >> b;
		start.pb(a); stop.pb(b);
	}
	sort(all(start)); sort(all(stop));

	int p1 = 0, p2 = 0;
	int ans = 0, cur = 0;
	while (p1<n) { // use 2p to simulate scan line
		if (p2==n || start[p1]<stop[p2]) {cur++; p1++;} // if the next endpoint is the start of a range
		else {cur--; p2++;} // if the next one is the end of the range
		chmax(ans,cur);
	} cout << ans << '\n';
}