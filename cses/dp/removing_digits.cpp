#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<int> dp(n+1,INT_MAX);
    dp[n] = 0;
    for (int i=n;i>=0;i--) {
        if (dp[i]==INT_MAX) {continue;}
        string s = to_string(i);
        for (char x : s) { // try removing all digits
            if (i-(x-'0')<0) {continue;}
            chmin(dp[i-(x-'0')],dp[i]+1);
        }
    } cout << dp[0] << '\n';
}