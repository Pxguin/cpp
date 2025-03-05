#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

const int MAX_N = 2e5, MAX_R = 25000;
v<int> adj[MAX_N];
int tin[MAX_N], tout[MAX_N], timer = 0;
int h[MAX_N];

v<int> cnt[MAX_R];
v<int> desc[MAX_R];
v<pii> anc[MAX_R];

void dfs(int cur, int par) { // euler tour
    tin[cur] = timer++;
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
        }
    }

    tout[cur] = timer;
    desc[h[cur]].pb(tin[cur]);
    anc[h[cur]].pb({tin[cur],1});
    anc[h[cur]].pb({tout[cur],-1});
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, r, q; cin >> n >> r >> q;
    cin >> h[0];

    F0R(i,n-1) {
        int p; cin >> p;
        adj[--p].pb(i+1);
        cin >> h[i+1];
    }
    F0R(i,n) {cnt[--h[i]].pb(i);}
    dfs(0,0);
    map<pii,int> dp;

    F0R(i,r) { // setup
        anc[i].pb({-1,0});
        sort(all(anc[i]));
        sort(all(desc[i]));
        FOR(j,1,anc[i].size()) {anc[i][j].s += anc[i][j-1].s;}
    }


    while (q--) {
        int r1, r2; cin >> r1 >> r2; r1--; r2--;
        int ans = 0;

        if (dp.count({r1,r2})) { // have we encountered this query before
            ans = dp[{r1,r2}];
        } else {
            if (cnt[r1].size()<=cnt[r2].size()) { // if sz[r1]<=sz[r2] then iterate over r1
                for (int x : cnt[r1]) { // calculate # descendants that each node with region r1 propagates to
                    ans += lower_bound(all(desc[r2]),tout[x])-lower_bound(all(desc[r2]),tin[x]);
                }
            } else { // otherwise, iterate over r2
                for (int x : cnt[r2]) { // calculate # ancestors that propagate to each node with region r2
                    ans += prev(upper_bound(all(anc[r1]),make_pair(tin[x],INT_MAX)))->s;
                }
            }
            dp[{r1,r2}] = ans; // memoize queries
        }
        cout << ans << endl;
    }
}