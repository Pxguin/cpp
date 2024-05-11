#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back

void solve() {
	ll n, w; cin >> n >> w;
	ll low = (w+1)/2;
	ll cur = 0;
	pii ok[n];
	vector<int> ans;
	for (int i=0;i<n;i++) {cin >> ok[i].f; ok[i].s = i+1;}
	sort(ok, ok+n, greater<>());

	for (pii i : ok) {
		if (cur + i.f > w) {continue;}
		cur += i.f; ans.pb(i.s);
		if (cur >= low) {break;}
	}

	if (cur >= low) {
		cout << ans.size() << '\n';
		for (int i : ans) {cout << i << ' ';}cout << '\n';
	} else {cout << "-1\n";}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}
