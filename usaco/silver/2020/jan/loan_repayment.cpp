#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll n, k, m;
bool check(ll x) {
	ll rem = n, days = 0;
	while (rem>0) {
		ll y = max(m,rem/x), add = 0;
		if (y==m) {add = ceil((ld)rem/m);} // if <= m then just finish
		else {add = ceil(((ld)rem-((y-1)*x+x-1))/y);} // how many days until y changes
		rem -= add*y;
		days += add;
	} return days<=k;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("loan.in","r",stdin);
	freopen("loan.out","w",stdout);

	cin >> n >> k >> m;

	ll l = 1, h = n, mid = (l+h)/2;
	ll ans;
	while (l<=h) {
		if (check(mid)) {l = mid+1; ans = mid;}
		else {h = mid-1;}
		mid = (l+h)/2;
	} cout << ans << '\n';
}