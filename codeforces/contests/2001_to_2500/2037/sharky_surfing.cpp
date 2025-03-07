#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int solve() {
	int n, m, l; cin >> n >> m >> l;
	int a, b;

	multiset<int> left;
	int power = 1, ans = 0;
	v<pii> hur(n), pup(m);
	F0R(i,n) {cin >> hur[i].f >> hur[i].s;}
	F0R(i,m) {cin >> pup[i].f >> pup[i].s;}

	F0R(i,n) {if (hur[i].s==l) {return -1;}} // edge case: one of the hurdles ends at position L

	int p1 = 0, p2 = 0;
	while (p2<hur.size()) {
		if (p1!=pup.size() && pup[p1].f < hur[p2].f) {left.insert(pup[p1].s); p1++;}
		else {
			int range = hur[p2].s-hur[p2].f+2;
			p2++;
			while (power<range && left.size()) { // take maximum powerup while necessary (priority queue works better)
				ans++;
				power += *left.rbegin();
				left.erase(--left.end());
			} if (power<range) {return -1;} // if it's still not enough then return -1
		}
	} return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {cout << solve() << '\n';}
}