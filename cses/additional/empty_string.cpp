#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	string s; cin >> s;
	int n = s.size();
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	
	const int mod = 1e9+7;
	auto add = [&](const int a, const int b)->int {return (a+b)%mod;};
	auto mul = [&](int a, int b)-> int {return (ll)a*b%mod;};

	vector<vector<int>> bc(n,vector<int>(n,1));
	for (int i=1;i<n;i++) {
		for (int j=1;j<i;j++) {
			bc[i][j] = add(bc[i-1][j],bc[i-1][j-1]);
		}
	}
	for (int i=0;i<n-1;i++) {dp[i][i+1]=(s[i]==s[i+1]);}
	for (int i=0;i<=n;i++) {for (int j=i+1;j<=n;j++) {dp[j][i]=1;}}

	for (int len=3; len<n; len+=2) { // length-1
		for (int pos=0; pos<n-len; pos++) { // start
			for (int i=pos+1; i<=pos+len; i+=2) {
				if (s[pos]==s[i]&&dp[pos+1][i-1]) {
					dp[pos][pos+len] = add(dp[pos][pos+len],mul(mul(dp[pos+1][i-1],dp[i+1][pos+len]),bc[(len+1)/2][(i-pos+1)/2]));
				}
			}
		}
	}
	cout << dp[0][n-1] << '\n';
}