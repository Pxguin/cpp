#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int mod = 1e9+9;
	int n, d; cin >> n >> d;
	vector<int> a(n); ll ans = 1;
	for (int i=0;i<n;i++) {cin >> a[i];}

	sort(a.begin(),a.end());
	auto it = a.begin();
	while (it!=a.end()) {
		int diff = (it++)-lower_bound(a.begin(),a.end(),*it-d)+1;
		ans = (ans*diff)%mod;
	} cout << ans << '\n';
}