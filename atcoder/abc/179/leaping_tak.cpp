#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int mod = 998244353;
void add(int& a, int b) {a = (a+b)%mod;}
int sub(int a, int b) {return (a-b+mod)%mod;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, k; cin >> n >> k;
	v<int> dp(n+1,0);
	dp[1] = 1;

	v<pii> seg(k);
	F0R(i,k) {cin >> seg[i].f >> seg[i].s;}

	FOR(i,2,n+1) {
		F0R(j,k) {
			add(dp[i],sub(dp[max(0,i-seg[j].f)],dp[max(0,i-seg[j].s-1)]));
		} add(dp[i],dp[i-1]);
	} cout << sub(dp[n],dp[n-1]) << '\n';
}