#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
int main() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int i=0;i<n;i++) {cin >> a[i];}
 
	auto solve = [&](int l, int r) {
		vector<ll> ret;
		int len = r-l+1;
		ll sum;
		for (int mask=0;mask<(1<<len);mask++) {
			sum = 0;
			for (int j=0;j<len;j++) {
				if (mask & (1<<j)) {sum += a[l+j];}
			}
			ret.pb(sum);
		}
		return ret;
	};
 
	vector<ll> left = solve(0, n/2-1);
	vector<ll> right = solve(n/2, n-1);
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	ll ans = 0;
 
	for (ll i : left) {
		auto it = upper_bound(right.begin(), right.end(), x-i);
		auto it2 = lower_bound(right.begin(), right.end(), x-i);
		ans += it-it2;
	}
	cout << ans << "\n";
}
