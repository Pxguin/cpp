#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)

using Cow = pair<pii,ll>;
vector<Cow> cows;
ll n, c, m;

bool check(ll x) {
	ll lb = max(0LL,x-m+1), rb = min(x,c-1);
	F0R(i,n) {
		ll a = cows[i].f.f, b = cows[i].f.s, t = cows[i].s;
		ld rhs = t-(a*c)-(b*m)+(b*x);
		if (b==a && rhs<0) {return false;}
		else if (b>a) {chmin(rb,(ll)floor(rhs/(b-a)));}
		else if (a>b) {chmax(lb,(ll)ceil(rhs/(b-a)));}
	} return (lb<=rb);
}

void solve() {
	cin >> n >> c >> m;
	cows.clear(); cows.resize(n);
	F0R(i,n) {cin >> cows[i].f.f >> cows[i].f.s >> cows[i].s;}

	ll l = 0, h = c+m-2, mid = (l+h)/2;
	ll ans = -1;
	while (l<=h) {
		if (check(mid)) {h = mid-1; ans = mid;}
		else {l = mid+1;}
		mid = (l+h)/2;
	} cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}