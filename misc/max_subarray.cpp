#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	int a[n];
	for (int i=0;i<n;i++) {cin >> a[i];}

	auto s1 = [&]() {
		int ps[n+1]; ps[0] = 0;
		for (int i=0;i<n;i++) {
			ps[i+1] = ps[i]+a[i];
		}
		int mn = 0, mx = 1, ans = 0;
		while (mx <= n) {
			int sum = ps[mx]-ps[mn];
			if (sum > 0) {ans = max(ans, sum);}
			else {mn = mx;}
			mx++;
		}
		cout << ans << '\n';
	};
	
	auto s2 = [&]() {
		int ans = 0, cur = 0;
		for (int i=0;i<n;i++) {
			cur += a[i];
			if (cur > 0) {ans = max(ans, cur);}
			else {cur = 0;}
		}
		cout << ans << '\n';
	};
	s1();
	s2();
}
