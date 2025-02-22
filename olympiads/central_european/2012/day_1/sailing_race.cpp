#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

const int MAX_N = 500;
int dp[MAX_N][MAX_N][2] = {0}, dp2[MAX_N][MAX_N][2] = {0};
int nxt[MAX_N][2];
int mx[MAX_N][MAX_N][2] = {0};
bool adj[MAX_N][MAX_N] = {false};

// ccw: 0; cw: 1
// dp[i][j][ccw/cw]: start at i, end at or past j, in the ccw/cw direction
// dp2[i][j][ccw/cw]: start at i, end at j, moving only in the ccw/cw direction

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, t; cin >> n >> t;

    F0R(i,n) {
        int x; cin >> x;
        while (x!=0) {
            adj[i][--x] = true;
            dp[i][x][0] = dp2[i][x][0] = dp[i][x][1] = dp2[i][x][1] = 1; // base cases for dp
            cin >> x;
        }
    }
    F0R(i,n) { // precalculate next port on both sides (this literally halves the runtime)
        nxt[i][0] = (i+1)%n;
        nxt[i][1] = (i-1+n)%n;
    }

    FOR(len,2,n) { // construct the race in reverse
        F0R(i,n) {
            int k = (i+len)%n;

            F0R(st,2) { // initially, only compute dp[i][j][cw/ccw] start at i, end at j
                for (int j=k;j!=i;j=nxt[j][!st]) { 
                    if (adj[i][j]) {
                        if (dp[j][k][st]) { // same direction line
                            chmax(dp[i][k][st],dp[j][k][st]+1);
                        }
                        if (dp2[j][k][st]) { // note: only one transition for dp2, whereas two for dp1
                            chmax(dp2[i][k][st],dp2[j][k][st]+1);
                        }
                    }
                    if (adj[i][k] && dp[k][j][!st]) { // opposite direction line
                        chmax(dp[i][k][st],dp[k][j][!st]+1);
                    }
                }
                k = (i-len+n)%n;
            }
        }
    }

    // now update dp such that dp[i][j][cw/ccw] = start at i, finish >=j (for ccw), <=j (for cw)
    F0R(i,n) {
        F0R(st,2) {
            for (int j=nxt[i][st];j!=i;j=nxt[j][st]) {
                chmax(dp[i][j][st],dp[i][nxt[j][!st]][st]);
            }
        }
    }

    int ans_zero = 0, start_zero = 0, ans_one = 0, start_one = 0;

    F0R(stop,n) { // fixing the end of the first line
        F0R(st,2) {

            // case k=0
            int cand_zero = dp[stop][nxt[stop][!st]][st];
            if (cand_zero>ans_zero) {
                ans_zero = cand_zero;
                start_zero = stop+1;
            }

            for (int start=nxt[stop][st];start!=stop;start=nxt[start][st]) { // fixing the start of the first line

                // case k=1: update radj and answer
                int cand_one = 0;
                
                for (int cand=nxt[stop][!st];cand!=start;cand=nxt[cand][!st]) { // test all possibilities for answer
                    
                    if (adj[start][stop] && mx[stop][cand][st]) { // (only if it's valid)
                        int aft = max(dp[cand][nxt[start][st]][!st],dp[cand][nxt[stop][!st]][st]);
                        chmax(cand_one,1+mx[stop][cand][st]+aft);

                    }
                    if (adj[start][cand] && dp2[stop][start][st]) { // update all candidates for answer because this start position can become a crossing point
                        chmax(mx[stop][cand][st],dp2[stop][start][st]+1);
                    }
                    
                }

                if (cand_one>ans_one) { // test against answer
                    ans_one = cand_one;
                    start_one = start+1;
                }
            }
        }
    }
    if (ans_zero>ans_one || t==0) {
        cout << ans_zero << '\n' << start_zero << '\n';
    } else {
        cout << ans_one << '\n' << start_one << '\n';
    }
}