#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)

ll solve() {
	ll n, m; cin >> n >> m;
	char c;
	vector<ll> a(n);
	vector<bool> dir(n);
	bool ok[2] = {0};
	ll ans = 0;
	F0R(i,n) {
		cin >> c;
		dir[i] = (c=='R');
		ok[c=='L']=true;
	}
	F0R(i,n) {
		cin >> a[i]; ans += a[i];
	} 
	if (ok[0]^ok[1]) {return ans;} // all R or all L
	int it;
	F0R(i,n) {if (dir[i]&&!dir[(i-1+n)%n]) {it = i; break;}}
	rotate(dir.begin(),dir.begin()+it,dir.end());
	rotate(a.begin(),a.begin()+it,a.end());

	bool prev = true;
	ll sum = 0;
	dir.pb(true); a.pb(0);
	F0R(i,n+1) {
		if (dir[i]==prev) {
			sum += a[i];
		} else {
			if (dir[i]) { // l to r
				ans -= min(sum,m);
				sum = 0;
			} else {
				sum -= a[i-1];
				ans -= min(sum,m);
				sum = -a[i];
			}
			prev = !prev; sum += a[i];
		}
	} return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cout << solve() << '\n';
}