#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define vec vector

int mod = 998244353;
const int MAX_N = 2e5, l2 = 21;

vec<int> adj[MAX_N], radj[MAX_N];
int dp[MAX_N][l2][2];
int mn[MAX_N][2];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m; cin >> n >> m;
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        radj[b].pb(a);
    }
    for (int i=0;i<n;i++) {adj[i].pb(i); radj[i].pb(i);}
    
    for (int i=0;i<n;i++) {
        mn[i][0] = mn[i][1] = INT_MAX;
        for (int j=0;j<l2;j++) {dp[i][j][0] = dp[i][j][1] = INT_MAX;}
    }
    
    using T = pair<pair<int,int>,int>;
    priority_queue<T,vec<T>,greater<T>> pq; // sorted by (flips,moves)
    pq.push({{0,dp[0][0][0]=0},0});

    auto upd = [&](vec<int>& adj1, int cur, int t, int d) {
        if (d==m+1) {return;}
        for (int x : adj1) {
            int w = (x!=cur), t1 = t+1-w, p = t1%2; // self-loop = flip graphs (w: delta distance; t1: delta flips, p: parity/which graph)
            if (t1>=l2-1) { // do transitions
                if (t1<mn[x][p] || (t1==mn[x][p] && d+w<dp[x][l2-1][p])) {
                    mn[x][p] = t1;
                    pq.push({{t1,dp[x][l2-1][p]=d+w},x});
                }
            } else {
                if (d+w<dp[x][t1][p]) {
                    pq.push({{t1,dp[x][t1][p]=d+w},x});
                }
            }
        }
    };
    while (pq.size()) {
        auto[t,d] = pq.top().f;
        int cur = pq.top().s; pq.pop();

        if ((t>=l2-1 && t!=mn[cur][t%2]) || d!=dp[cur][min(l2-1,t)][t%2]) {continue;}
        if (t%2==0) { // if even number of transpositions, use adj
            upd(adj[cur],cur,t,d);
        } else { // else, use radj
            upd(radj[cur],cur,t,d);
        }
    }
    
    int flips = INT_MAX, moves = INT_MAX;
    int ans = INT_MAX;
    for (int i=0;i<2;i++) { // calculate best answer
        if (mn[n-1][i]!=INT_MAX) {
            if (mn[n-1][i]<flips || (mn[n-1][i]==flips && dp[n-1][l2-1][i]<moves)) {
                flips = mn[n-1][i]; moves = dp[n-1][l2-1][i];
            }
        }
        for (int j=1;j<l2-1;j++) {
            if (dp[n-1][j][i]==INT_MAX) {continue;}
            chmin(ans,(dp[n-1][j][i]+(1<<j)-1)%mod);
        }
    }
    int pows = 1;
    for (int i=0;i<flips;i++) {pows = (pows*2)%mod;}
    chmin(ans,(moves+pows-1)%mod);
    
    cout << ans << '\n';
}