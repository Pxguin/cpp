#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_N 10001
#define pb push_back

bool prime[MAX_N];
vector<int> primes;
int n;

void calc_primes() {
	for (int i=0;i<=n;i++) {prime[i] = true;}
	for (int i=2;i*i<=n;i++) {
		if (prime[i]) {
			for (int j=i*i;j<=n;j+=i) {prime[j] = false;}
		}
	}
	for (int i=2;i<=n;i++) {if (prime[i]) {primes.pb(i);}}
}

int main() {
	freopen("exercise.in","r",stdin);
	freopen("exercise.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll m; cin >> n >> m;

	calc_primes();
	int p = primes.size();
	vector<vector<ll>> dp(p+1, vector<ll>(n+1,0));
	for (int i=0;i<=n;i++) {dp[0][i] = 1;}
	for (int i=0;i<=p;i++) {dp[i][0] = 1;}

	for (int i=1;i<=p;i++) {
		for (int j=1;j<=n;j++) {
			dp[i][j] = dp[i-1][j];
			ll ok = primes[i-1];
			while (ok <= j) {
				dp[i][j] = (dp[i][j]+(dp[i-1][j-ok]*ok % m)) % m;
				ok = (ok*primes[i-1]) % m;
			}
		}
	}
	cout << dp[p][n] << '\n';
}
