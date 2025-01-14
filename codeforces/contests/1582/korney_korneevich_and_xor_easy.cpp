#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    v<int> a(n+1);
    v<v<int>> dp(n+1,v<int>(512,501)); // 501 = impossible
    F0R(i,n) {cin >> a[i];}

    dp[0][0] = -1;
    F0R(i,n) {
        F0R(x,512) {
            chmin(dp[i+1][x],dp[i][x]); // don't add to subsequence
            if (dp[i][x]<a[i]) { // add to subsequence (if possible)
                chmin(dp[i+1][x^a[i]],a[i]);
            }
        }
    }
    v<int> ans;
    F0R(i,512) {
        if (dp[n][i]!=501) {ans.pb(i);}
    }
    cout << ans.size() << '\n';
    for (int i : ans) {cout << i << ' ';}
}