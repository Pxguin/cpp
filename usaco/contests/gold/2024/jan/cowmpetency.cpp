#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

ll mod = 1e9+7;
ll mul(ll a, ll b) {return a*b%mod;}
ll add(ll a, ll b) {return (a+b)%mod;}
ll sub(ll a, ll b) {return (a-b+mod)%mod;}

ll exp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b%2) {res = mul(res,a);}
		b /= 2;
		a = mul(a,a);
	} return res;
}

ll solve() {
	int n, q, c; cin >> n >> q >> c;
	v<pii> r(q);
	F0R(i,q) {cin >> r[i].f >> r[i].s;}
	sort(all(r));
	
	v<ll> dp(c+1,1); dp[0] = 0;
	int last = 1;
	F0R(i,q) {
		auto[a,h] = r[i];
		if (h==last) {continue;} // if you have nested ranges with same h value
		if (a<last) {return 0;} // if they are not disjoint

		v<ll> dp2(c+1,0);
		if (a==last) {dp2 = dp;} // side case: two ranges touch at an endpoint
		else {
			ll ps = 0;
			FOR(j,1,c+1) { // deal with a_i
				dp2[j] = mul(ps,sub(exp(j,a-last),exp(j-1,a-last)));
				ps = add(ps,dp[j]);
				dp2[j] = add(dp2[j],mul(dp[j],exp(j,a-last)));
				dp[j] = 0;
			}
		}
		FOR(j,1,c+1) { // deal with h_i (minus 1)
			dp[j] = mul(dp2[j],exp(j,h-a-1));
			dp2[j] = 0;
		}
		FOR(j,1,c+1) { // deal with h_i
			dp2[j] = add(dp2[j-1],dp[j-1]);
		}
		last = h;
		dp = dp2;
	} 
	ll ans = 0;
	F0R(i,c+1) {ans = add(ans,dp[i]);}
	ans = mul(ans,exp(c,n-last)); // take care of cows after last h_i
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cout << solve() << '\n';
}