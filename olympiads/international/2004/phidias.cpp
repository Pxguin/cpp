#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int w, h, n, w1, h1; cin >> w >> h >> n;
	vector<vector<int>> dp(w+1,vector<int>(h+1,INT_MAX));
	F0R(i,w+1) {
		F0R(j,h+1) {dp[i][j] = i*j;}
	}
	F0R(i,n) {cin >> w1 >> h1; dp[w1][h1]=0;}

	F0R(i,w+1) {
		F0R(j,h+1) {
			F0R(k,j+1) {
				if (j+k <= h) {dp[i][j+k] = min(dp[i][j+k],dp[i][j]+dp[i][k]);}
			}
			F0R(k,w+1) {
				if (i+k <= w) {dp[i+k][j] = min(dp[i+k][j],dp[i][j]+dp[k][j]);}
			}
		}
	}
	cout << dp[w][h] << '\n';
} 	