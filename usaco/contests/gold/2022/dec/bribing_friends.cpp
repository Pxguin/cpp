#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

struct Friend {
    int p, c, x;
    Friend (int p, int c, int x) : p(p), c(c), x(x) {};
    bool operator<(const Friend& y) {return x < y.x;}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, a, b; cin >> n >> a >> b;
    v<Friend> f; 
    F0R(i,n) {
        int a1, b1, c1; cin >> a1 >> b1 >> c1;
        f.pb(Friend(a1,b1,c1));
    } sort(all(f));

    v<v<int>> dp(n+1,v<int>(b+1,0)); // max popularity, cows [1,i], B cones left
    v<v<int>> dp2(n+1,v<int>(a+1,0)); // max popularity, cows [i,n], A moonies left
    F0R(i,n) {
        Friend f1 = f[i];
        F0R(j,b+1) {
            dp[i+1][j] = dp[i][j];
            if (f1.x*f1.c<=j) {chmax(dp[i+1][j-(f1.x*f1.c)],dp[i][j]+f1.p);}
        }
    }
    for (int i=n;i;i--) {
        Friend f1 = f[i-1];
        F0R(j,a+1) {
            dp2[i-1][j] = dp2[i][j];
            if (j>=f1.c) {chmax(dp2[i-1][j],dp2[i][j-f1.c]+f1.p);}
        }
    }
    int ans = 0;
    F0R(i,n) { // friend i is the bridge between using cones and moonies
        F0R(j,b+1) {
            int left = max(0,f[i].c-j/f[i].x); // calc # remaining moonies to pay after using all remaining cones
            if (left>a) {continue;}
            chmax(ans,dp[i][j]+f[i].p+dp2[i+1][a-left]);
        }
    } cout << ans << '\n';
}