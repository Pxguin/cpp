#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	ll n, k; cin >> n >> k;
	ll a[k];
	F0R(i,k) {cin >> a[i];}

	ll ans = 0;
	FOR(i,1,(1<<k),1) {
		int cnt = 0; vector<ll> prime;
		ll sum = 1;
		F0R(j,k) {
			if ((1<<j)&i) {
				cnt++;
				if (n/sum >= a[j]) {sum *= a[j];}
				else {sum = n+1;}
			}
		} ans += (n/sum)*(cnt%2 ? 1 : -1);
	} cout << ans << '\n';
}