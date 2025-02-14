#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, x, y; cin >> n >> x >> y;
    int ans = 0;

    int dp[81][10001];
    for (int i=0;i<81;i++) for (int j=0;j<10001;j++) {dp[i][j] = INT_MAX;}
    dp[0][0] = 0;

    for (int i=0;i<n;i++) {
        int a, b; cin >> a >> b;
        for (int num=n-1;num>=0;num--) {
            for (int swt=x-a;swt>=0;swt--) {
                if (dp[num][swt]==INT_MAX) {continue;}

                if (dp[num][swt]+b<=y) { // if saltiness passes
                    chmin(dp[num+1][swt+a],dp[num][swt]+b); // change dp
                    chmax(ans,num+1);
                }
            }
        }
    }
    cout << min(ans+1,n) << '\n';
}