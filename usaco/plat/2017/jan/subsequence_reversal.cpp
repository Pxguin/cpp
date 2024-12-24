#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int dp[50][50][50][50]={0};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("subrev.in","r",stdin);
    freopen("subrev.out","w",stdout);
    
    int n; cin >> n;
    v<int> a(n);
    F0R(i,n) {cin >> a[i]; a[i]--;}

    F0R(i,n) {dp[i][i][a[i]][a[i]]=1;}
    F0R(i,n) {
        FOR(j,i+1,n) {
            dp[i][j][min(a[i],a[j])][max(a[i],a[j])]=2;
        }
    }

    int ans = min(n,2);
    FOR(sz,2,n) {
        F0R(l,n-sz) {
            int r = l+sz;
            F0R(mn,50) {
                FOR(mx,mn,50) {
                    chmax(dp[l][r][mn][mx],max(dp[l][r-1][mn][mx],dp[l+1][r][mn][mx])); // don't do anything
                    if (a[l]>a[r]&&a[l]>=mx&&a[r]<=mn && dp[l+1][r-1][mn][mx]) {chmax(dp[l][r][a[r]][a[l]],dp[l+1][r-1][mn][mx]+2);} // swap outermost cows
                    if (a[l]<=mn && dp[l+1][r][mn][mx]) {chmax(dp[l][r][a[l]][mx],dp[l+1][r][mn][mx]+1);} // extend 1 on the left side (by default)
                    if (a[r]<=mn && dp[l+1][r-1][mn][mx]) {chmax(dp[l][r][a[r]][mx],dp[l+1][r-1][mn][mx]+1);} // extend 1 on the left side (by swapping cows)
                    if (a[r]>=mx && dp[l][r-1][mn][mx]) {chmax(dp[l][r][mn][a[r]],dp[l][r-1][mn][mx]+1);} // extend 1 on right side (case 1)
                    if (a[l]>=mx && dp[l+1][r-1][mn][mx]) {chmax(dp[l][r][mn][a[l]],dp[l+1][r-1][mn][mx]+1);} // 1 on right side (case 2)
                }
            }
            F0R(mn,50) {
                FOR(mx,mn,50) {chmax(ans,dp[l][r][mn][mx]);}
            }
        }
    }
    
    cout << ans << '\n';
}