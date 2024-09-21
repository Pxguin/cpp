#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector<int> h(n);
	int lim = INT_MAX;
	F0R(i,n) {cin >> h[i];}
	F0R(i,n) {lim = min(lim,h[i]+1);}

	if (n%2==0) {lim = 1;}
	int ans = 0, mod = 1e9+7;

	auto add = [&](int a, int b) {return (a+b)%mod;};

	F0R(target,lim) { // get everything to target value Ok (which is 0)
		vector<vector<int>> dp(n,vector<int>(1001,0));
		F0R(i,h[0]+1) {dp[0][i] = 1;}

		vector<int> ps(1001);
		FOR(i,1,n) {
			ps[0] = dp[i-1][0];
			F0R(j,1001) {ps[j+1]=add(dp[i-1][j+1],ps[j]);}
            
			F0R(j,h[i]+1) {dp[i][j]=ps[h[i]-j];}
		} ans = add(ans,dp[n-1][0]);
		
		F0R(i,n) {h[i]--;}
	} cout << ans << '\n';
}