#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("diamond.in","r",stdin);
	freopen("diamond.out","w",stdout);
	int n, k; cin >> n >> k;
	ll a[n], sums[n], ps[n+1];
	for (int i=0;i<n;i++) {cin >> a[i]; ps[i] = 0;}
	sort(a, a+n);
	int p1 = 0, p2 = 0;
	while (p1 < n) {
		while (p2 < n) {
			if (a[p2++]-a[p1] > k) {p2--; break;}
		}
		sums[p1++] = p2-p1;
	}
	ps[n] = 0;
	for (int i=n-1;i>=0;i--) {
		ps[i] = max(ps[i+1], sums[i]);
	}
	ll ans = 0;
	for (int i=0;i<n;i++) {
		ans = max(ans, sums[i] + ps[i+sums[i]]);
	}
	cout << ans << "\n";
}

/*

it is always optimal to take the max 2p, 
obviously no use in saving it for the second case

so try building the first case from all i

then, for each i have to build the second case
logically want to take the max of the case to the right of p2
and the case to the left of p1

then add it to the current ctr
requires prefix and suffix sums

but suffix sums are actually not necessary, because you will have already
tried the suffix sum sequence in the prefix. so only take the prefix

similar to: running miles, yet another monster fight

*/
