#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int n;
int a[50],b[50];
bool ok[51], reach[51];

bool check() {
	bool ret = 1;
	F0R(i,n) {
		F0R(j,51) {reach[j] = false;}
		reach[a[i]] = true;
		queue<int> q; q.push(a[i]);
		while (q.size()) {
			int cur = q.front(); q.pop();
			FOR(j,1,51) {
				if (ok[j] && !reach[cur%j]) {
					reach[cur%j] = true; q.push(cur%j);
				}
			}
        } 
        ret &= reach[b[i]];
	} return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	F0R(i,n) {cin >> a[i];}
	F0R(i,n) {cin >> b[i];}
	F0R(i,51) {ok[i] = true;}

	ll ans = 0;
	if (!check()) {ans = -1;}
	else {
		for (ll k=50;k;k--) {
			ans += (1LL<<k);
			ok[k] = false;
			if (check()) {ans -= (1LL<<k);}
			else {ok[k] = true;}
		} 
	} cout << ans << '\n';
}