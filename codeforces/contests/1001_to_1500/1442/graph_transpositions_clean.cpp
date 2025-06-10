#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 2e5, l2 = 20, mod = 998244353;

struct State {
    int flips, moves;
    bool operator<(const State& o) const {
        if (flips>=l2 && o.flips>=l2) {return (flips==o.flips ? moves<o.moves : flips<o.flips);}
        if (flips>=l2) {return 0;}
        if (o.flips>=l2) {return 1;}
        return moves+(1<<flips)<o.moves+(1<<o.flips);
    }
    bool operator!=(const State& o) const {
        return flips!=o.flips || moves!=o.moves;
    }
} dp[MAX_N][l2+1][2];

struct PQState {
    State s1; int cur;
    bool operator<(const PQState& o) const {return o.s1<s1;}
};

vec<int> adj[MAX_N], radj[MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        radj[b].pb(a);
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<=l2;j++) {dp[i][j][0] = dp[i][j][1] = {INT_MAX,INT_MAX};}
    }

    dp[0][0][0] = {0,0};
    priority_queue<PQState> pq;
    pq.push({(State){0,0},0});

    while (pq.size()) {
        State st = pq.top().s1;
        int cur = pq.top().cur; pq.pop();
        int layer = st.flips%2;

        if (st!=dp[cur][min(l2,st.flips)][layer]) {continue;}

        for (int x : (layer ? radj[cur] : adj[cur])) { // flip graphs
            if ((State){st.flips,st.moves+1}<dp[x][min(l2,st.flips)][layer]) {
                dp[x][min(l2,st.flips)][layer] = {st.flips,st.moves+1};
                pq.push({dp[x][min(l2,st.flips)][layer],x});
            }
        }
        if ((State){st.flips+1,st.moves}<dp[cur][min(l2,st.flips+1)][layer^1]) { // traverse along graph (don't flip)
            dp[cur][min(l2,st.flips+1)][layer^1] = {st.flips+1,st.moves};
            pq.push({dp[cur][min(l2,st.flips+1)][layer^1],cur});
        }
    }
    
    State ans = {INT_MAX,INT_MAX};
    for (int i=0;i<=l2;i++) {chmin(ans,min(dp[n-1][i][0],dp[n-1][i][1]));}
    int pows = 1;
    for (int i=0;i<ans.flips;i++) {pows = (pows*2)%mod;}
    cout << (ans.moves+pows-1)%mod << '\n';
}