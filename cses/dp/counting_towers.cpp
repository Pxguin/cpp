#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mod = 1e9+7;
ll dp[1000001][2];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    dp[1][0] = 1; // dp[i][0/1]: height i, is there a big block on top 
    dp[1][1] = 1;

    for (int i=1;i<1000000;i++) {
        dp[i+1][1] = (2LL*dp[i][1]+dp[i][0])%mod; // add big block/extend big block
        dp[i+1][0] = (dp[i][1]+4LL*dp[i][0])%mod; // add small blocks/extend small blocks
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << (dp[n][0]+dp[n][1])%mod << '\n';
    }
}