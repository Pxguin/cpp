#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)

const int MAX_N = 2e5, l2 = 30, mod = 998244353;
int a[MAX_N+1], nxt[MAX_N+1][l2];
unordered_map<int,int> dp[MAX_N+1];

int main() {
    int n; cin >> n;
    for (int i=0;i<n;i++) {cin >> a[i];}
    fill(nxt[n-1],nxt[n-1]+l2,n);
    for (int i=n-1;i>0;i--) { // for each i and bit b, calculate min j (j>i) with bit b turned on
        for (int j=0;j<l2;j++) {
            if ((1<<j)&a[i]) {nxt[i-1][j] = i;}
            else {nxt[i-1][j] = nxt[i][j];}
        }
    }
    dp[0][a[0]] = 1;
    for (int i=0;i<n-1;i++) {
        for (auto[x,w] : dp[i]) { // x = OR of current segment, w = amount of ways
            int to = n, cur = i+1; // must find earliest index "to" such that OR of [i+1,to]>=x
            for (int j=l2-1;j>=0;j--) { // process bits most to least significant
                if ((1<<j)&x) {
                    chmax(cur,nxt[i][j]);
                } else { // if the bit is turned off in x, then try turning it on in the next segment
                    chmin(to,max(cur,nxt[i][j]));
                }
            }
            chmin(to,cur); // if OR of both segments are the same
            
            if (to!=n) {
                int val = 0; // OR of the next segment
                for (int j=0;j<l2;j++) { // figure out which bits are turned on in the OR of the next segment
                    if (nxt[i][j]<=to) {val ^= (1<<j);}
                }
                dp[to][val] = (dp[to][val]+w)%mod;
            }

            dp[i+1][x|a[i+1]] = (dp[i+1][x|a[i+1]]+w)%mod; // extend the current segment
        }
    }
    int ans = 0;
    for (auto[x,w] : dp[n-1]) {ans = (ans+w)%mod;}
    cout << ans << '\n';
}