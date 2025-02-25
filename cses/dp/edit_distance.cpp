#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();

    v<v<int>> dp(n+2,v<int>(m+2,INT_MAX));
    dp[0][0] = 0;
    F0R(i,n+1) {
        F0R(j,m+1) {
            chmin(dp[i+1][j+1],dp[i][j]+(s1[i]!=s2[j])); // replace character, or no edit needed
            chmin(dp[i][j+1],dp[i][j]+1); // add character
            chmin(dp[i+1][j],dp[i][j]+1); // delete character
        }
    }
    cout << dp[n][m] << '\n';
}