#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

const int MAX_N = 1e5;
v<int> adj[MAX_N];
int dp[MAX_N];
bool fail = false;

bool check(v<int>& paths, int skp, int k) {
    int ptr = 0;
    for (int i=paths.size()-1;i>=0;i--) { // greedily pair up paths with 2p
        if (i==skp) {continue;}
        if (ptr==skp) {ptr++;}
        if (i==ptr && paths[i]<k) {return false;}
        if (paths[i]+paths[ptr]<k) {return false;}
        ptr++;
    } return true;
}

void dfs(int cur, int par, int k) {
    v<int> paths;
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur,k);
            paths.pb(dp[x]+1);
        }
    }
    sort(all(paths));

    int l = 0, h = paths.size()-1, m = (l+h)/2;
    dp[cur] = (check(paths,-1,k) ? 0 : -1); // can we pair up all paths
    if (cur==0 && dp[cur]==0) {dp[cur] = INT_MAX;} // it's beneficial to do this if we're at the root

    while (l <= h) { // binary search on largest path length left unpaired
        if (check(paths,m,k)) {
            dp[cur] = max(dp[cur],paths[m]);
            l = m+1;
        } else {h = m-1;}
        m = (l+h)/2;
    }
    if (dp[cur]==-1) {fail = true;}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("deleg.in","r",stdin);
    freopen("deleg.out","w",stdout);

    int n; cin >> n;
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b); adj[b].pb(a);
    }
    int l = 1, h = n-1, m = (l+h)/2, ans;
    while (l <= h) { // binary search on K
        fail = false;
        memset(dp,0,sizeof(dp));
        dfs(0,0,m);
        if (!fail && dp[0]>=m) {
            l = m+1;
            ans = m;
        } else {h = m-1;}
        m = (l+h)/2;
    } cout << ans << '\n';
}