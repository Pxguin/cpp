#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second

int ps[1001][1001];

int sum(int x1, int y1, int x2, int y2) {
	return ps[x2][y2]-ps[x2][y1-1]-ps[x1-1][y2]+ps[x1-1][y1-1];
}

int main() {
	freopen("balancing.in","r",stdin);
	freopen("balancing.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int a, b;
	pii cows[n];
	for (int i=0;i<n;i++) {
		cin >> a >> b;
		cows[i] = mp(a,b);
	}
	sort(cows, cows+n);
	int replace[n]; replace[0] = 1;
	for (int i=1;i<n;i++) {replace[i] = (cows[i].f == cows[i-1].f ? replace[i-1] : i+1);}
	for (int i=0;i<n;i++) {cows[i].f = replace[i]; replace[i] = 0;}
	replace[0] = 1;
	sort(cows, cows+n, [&](const pii& x, const pii& y) {return x.s < y.s;});
	for (int i=1;i<n;i++) {replace[i] = (cows[i].s == cows[i-1].s ? replace[i-1] : i+1);}
	for (int i=0;i<n;i++) {cows[i].s = replace[i];}
	
	for (pii x : cows) {ps[x.f][x.s]++;}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			ps[i][j] = ps[i][j]+ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1];
		}
	}
	int ans = n;

	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			int mx = 0;
			mx = max(mx, sum(1,1,i,j));
			mx = max(mx, sum(i+1,1,n,j));
			mx = max(mx, sum(1,j+1,i,n));
			mx = max(mx, sum(i+1,j+1,n,n));
			ans = min(ans, mx);
		}
	}
	cout << ans << '\n';
}
