#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define vec vector

const int N = 400, K = 19;
vec<int> adj[N];
int dep[N] = {-1};
pair<int,int> range[N];
int dp[1<<K] = {0};
int k;
int m = 0;

void dfs(int cur=0, int par=-1) {
    range[cur] = {INT_MAX,INT_MIN};
    if (dep[cur]==k-1) {
        m++;
        range[cur] = {m,m};
        return;
    }
    for (int x : adj[cur]) {
        if (x!=par) {
            dep[x] = dep[cur]+1;
            dfs(x,cur);
            chmin(range[cur].f,range[x].f);
            chmax(range[cur].s,range[x].s);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n >> k;
    k = min(19,k);
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs();

    for (int i=0;i<(1<<k);i++) {
        for (int j=1;j<n;j++) {
            if ((1<<dep[j])&i) {continue;}
            if (range[j].f<=dp[i]+1) {
                chmax(dp[i|(1<<dep[j])],max(range[j].s,dp[i]));
            }
        }
    }
    cout << (dp[(1<<k)-1]==m ? "DA" : "NE") << '\n';
}