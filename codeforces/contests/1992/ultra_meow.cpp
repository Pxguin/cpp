#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

vector<vector<ll>> bc(5001,vector<ll>(5001,0));
ll mod = 1e9+7;
void precalc() {
	F0R(i,5001) {
		bc[i][0] = bc[i][i] = 1;
	}
	F0R(i,5001) {
		FOR(j,1,min(i,5001),1) {
			if (i!=j) {bc[i][j] = (bc[i-1][j-1]+bc[i-1][j])%mod;}
		}
	}
}

ll add(ll a, ll b) {return (a+b)%mod;}

void solve() {
	int n; cin >> n;
	ll ans = 0;
	F0R(i,n+1) { // |b|, going from [|b|+1, 2|b|+1]
		ll base = min(2*i,n);
		ans = add(ans,(bc[base][i])*(2*i+1)%mod); // base case
		for (int j=2*i;j>=i+1;j--) { // [|b|+1,2|b|]
			if (n-j<=0) {break;}
			ll delta = (2*i+1)-j;
			ll front = bc[base-delta][i-delta];
			ll back = bc[n-j][delta];
			ans = add(ans,(front*back)%mod*j%mod);
		}
	} cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	precalc();
	int t; cin >> t;
	while (t--) {solve();}
} 	