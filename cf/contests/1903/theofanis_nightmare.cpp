#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
void solve() {
	int n; cin >> n;
	ll a[n];
	for (int i=0;i<n;i++) {cin >> a[i];}
	ll sum = 0, ans = 0;
	vector<ll> groups;
 
	while (--n >= 0) {
		if (sum < 0) {
			groups.back() += a[n];
		} else {
			groups.pb(a[n]);
		}
		sum += a[n];
	}
 
	for (int i=0;i<groups.size();i++) {
		ans += groups[i]*(ll)(groups.size()-i);
	}
 
	cout << ans << "\n";
}
 
int main() {
	int t; cin >> t;
	while (t--) {solve();}
}