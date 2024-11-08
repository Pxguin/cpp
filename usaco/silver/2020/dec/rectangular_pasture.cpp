#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	pair<int,int> cows[n];
	for (int i=0;i<n;i++) {
		cin >> cows[i].f >> cows[i].s;
	}
	int ps[2502][2502];
	ll ans = 0;
	sort(cows, cows+n);
	for (int i=0;i<n;i++) {cows[i].f = i+1;}
	sort(cows, cows+n, [&](const auto i, const auto j){return i.s < j.s;});
	for (int i=0;i<n;i++) {cows[i].s = i+1;}

	for (int i=0;i<n;i++) {ps[cows[i].f][cows[i].s] = 1;}
	for (int i=1;i<n+1;i++) {
		for (int j=1;j<n+1;j++) {
			ps[i][j] += ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
		}
	}
	const auto sum = [&](const int x, const int y, const int X, const int Y) {
		return (ll)(ps[X][Y]-ps[x-1][Y]-ps[X][y-1]+ps[x-1][y-1]);
	};

	for (int i=0;i<n;i++) {
		for (int j=i;j<n;j++) {
			int mn = min(cows[i].f, cows[j].f);
			int mx = max(cows[i].f, cows[j].f);
			int mn2 = min(cows[i].s, cows[j].s);
			int mx2 = max(cows[i].s, cows[j].s);
			ans += (ll)sum(mn, 1, mx, mn2)*sum(mn, mx2, mx, n);
		}
	}
	cout << ans+1 << "\n";
}
