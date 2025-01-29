#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, t; cin >> t >> n;
	vector<vector<bool>> dp(3*n+1,vector<bool>(1<<n,false));
	dp[0][0] = true;

	auto shift = [&](int cur)->int {return (cur>>1)|((cur&1)<<(n-1));};
	FOR(i,1,3*n+1) {
		F0R(mask,1<<n) {
			int xor_ = (1<<(i%(n+1)))-1;
			F0R(j,n) {
				int x = (i>n&&i<=2*n ? xor_^((1<<n)-1) : xor_);
				if (dp[i-1][mask^x]) {dp[i][mask] = true;}
				xor_ = shift(xor_);
			}
		}
	}

	while (t--) {
		string a, b; cin >> a >> b;
		int l = 0, s = 0;
		F0R(i,n) {
			l ^= (a[i]=='1')<<(n-i-1);
			s ^= (b[i]=='1')<<(n-i-1);
		} int tot = 0;
		F0R(i,3*n+1) {
			if (dp[i][l^tot]) {cout << i << '\n'; break;}
			tot ^= s;
			s = shift(s);
		}
	}
}