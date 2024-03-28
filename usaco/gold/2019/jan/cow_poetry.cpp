#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define mp make_pair

ll MOD = 1e9+7;
int n, m, k;

ll calc(ll x, vector<ll>& lines) {
	ll ret = 0;
	for (ll i : lines) {		
		if (i) {
			// there are i^x possible combinations
			ll ans = 1, n = x;
			ll a = i;
			while (n > 0) {
				if (n%2) {ans = ans*a % MOD;}
				a = a*a % MOD;
				n /= 2;
			}
			ret = (ret+ans) % MOD;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("poetry.in","r",stdin);
	freopen("poetry.out","w",stdout);

	cin >> n >> m >> k;
	ll dp[k*2+1] = {0}; dp[0] = 1;
	ll s, c;
	vector<ll> lines(n,0);
	pair<ll,ll> words[n];

	// computing all lines
	for (int i=0;i<n;i++) {
		cin >> s >> c;
		words[i] = mp(s, --c);
	}
	for (int i=1;i<=k;i++) {
		for (pair<ll,ll> j : words) {
			if (i-j.f >= 0) {
				dp[i] = (dp[i]+dp[i-j.f]) % MOD;
			}
		}
	}
	for (int i=0;i<n;i++) {
		lines[words[i].s] = (lines[words[i].s] + dp[k-words[i].f]) % MOD;
	}

	// computing all poems
	char x; 
	int poem[26] = {0};
	for (int i=0;i<m;i++){
		cin >> x;
		poem[x-'A']++;
	}
	ll ans = 1;
	sort(poem, poem+26, greater<>());
	for (int i : poem) {
		if (i) {
			ll sum = calc((ll)i, lines);
			ans = (ans*sum) % MOD;
		}
	}
	cout << ans << '\n';
}