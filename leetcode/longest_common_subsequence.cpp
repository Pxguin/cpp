#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
		int n = text1.length(), m = text2.length();
		text1 += '.'; text2 += ',';
		vector<vector<int>> dp(n+2,vector<int>(m+2,0));
		F0R(i,n+1) {
			F0R(j,m+1) {
				dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+(text1[i]==text2[j]));
				dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
				dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
			}
		} return dp[n][m];
    }
};