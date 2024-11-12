#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int mod = 1e9+7;
int add(int a, int b) {return (a+b)%mod;}
int sub(int a, int b) {return (a+mod-b)%mod;}

void solve() {
	int n; cin >> n;
	char c;
	v<int> a(n+1,1),b(n+1,1);
	F0R(i,n) {
		cin >> c;
		a[i] = c-'0';
	}
	F0R(i,n) {
		cin >> c;
		b[i] = c-'0';
	}
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	v<v<int>> dp(n+1,v<int>(n+1,0));
	v<v<bool>> zero(n+1,v<bool>(n+1,false));
	
	F0R(i,n+1) {dp[i][0] = dp[0][i] = 1;}
	zero[1][0] = (a[0]==0); zero[0][1] = (b[0]==0);
	FOR(i,1,n+1) {
		FOR(j,1,n+1) {
			zero[i][j] = (zero[i-1][j]||zero[i][j-1]||!a[i-1]||!b[j-1]);
			dp[i][j] = sub(add(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
			
			// if one is a number that changes product and the other is a var then ok
			if (a[i]>=0&&b[j]<0 && (a[i]!=1&&!zero[i][j])) {dp[i][j] = add(dp[i][j],dp[i-1][j-1]);}
			if (a[i]<0&&b[j]>=0 && (b[j]!=1&&!zero[i][j])) {dp[i][j] = add(dp[i][j],dp[i-1][j-1]);}
		}
	} cout << dp[n][n] << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}