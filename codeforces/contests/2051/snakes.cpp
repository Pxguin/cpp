#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;
    v<pii> ev(q); char c;
    F0R(i,q) {cin >> ev[i].f >> c; ev[i].s = (c=='+');}

    n++;
    v<v<pii>> ptr(n,v<pii>(n,{0,1}));
    v<v<int>> cost(n,v<int>(n,1));

    F0R(i,q) {
        int s1 = ev[i].f-1;
        F0R(s2,n) { // 2p algorithm: we test each pair of snakes
            auto& [l,r] = ptr[s1][s2]; // l = end of first snake, and r = start of second snake
            if (ev[i].s) { // if this is the first snake in the pair that we're testing
                l++;
                if (l==r) {r++; cost[s1][s2]++;} // if they collide, move the second snake right one unit
            }
        }
        F0R(s2,n) { // second snake in pair
            auto& [l,r] = ptr[s2][s1];
            if (!ev[i].s) {r++;}
        }
    }
    F0R(i,n) {
        cost[i][i] = cost[n-1][i] = 1e7;
    }
    
    v<v<int>> dp((1<<n),v<int>(n,1e7));
    F0R(i,n) {dp[1<<i][i] = 1;}

    F0R(mask,(1<<n)) {
        F0R(bit,n) {
            if (!(mask&(1<<bit))) { // try adding a new snake
                F0R(last,n) {
                    if (mask&(1<<last)) { // transition from all previously added snakes
                        chmin(dp[mask|(1<<bit)][bit],dp[mask][last]+cost[last][bit]);
                    }
                }
            }
        }
    }
    cout << dp[(1<<n)-1][n-1]-1;
}