#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair

void solve() {
	int n, k; cin >> n >> k;
	pii a[n];
	for (int i=0;i<n;i++) {cin >> a[i].f; a[i].s = i;}
	sort(a,a+n,greater<>());
	int mx = 0, mx2 = 0, n1, n2;
	for (int i=0;i<n-1;i++) {
		int b = 0, c=0;
		for (int j=0;j<k;j++) {
			if ((a[i].f&(1<<j)) == (a[i+1].f&(1<<j))) {
				b |= (1<<j);
				c |= (a[i].f)&(1<<j);
			}
		}
		if (b >= mx) {n1 = a[i].s; n2 = a[i+1].s; mx = b; mx2=c;}
	}
	int x = ((1<<k)-1)^mx2;
	cout << n1+1 << ' ' << n2+1 << ' ' << x << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}
