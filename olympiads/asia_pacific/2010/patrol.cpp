#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmax(a, b) a = max(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

int n, k, ans = 0;

const int MAX_N = 1e5;
vec<int> adj[MAX_N];
int dp1[MAX_N] = {0}, dp2[MAX_N] = {0}, mxdep[MAX_N] = {0};

void dfs(int cur) {
    vec<int> dep;
    int dp1mx = 0, dp1mx2 = 0;
    for (int x : adj[cur]) {
        adj[x].erase(find(all(adj[x]),cur));
        dfs(x);
        dep.pb(mxdep[x]+1);

        chmax(dp2[cur],dp2[x]+1);
        chmax(dp1[cur],dp1[x]);

        if (dp1[x]>=dp1mx) {dp1mx2 = dp1mx; dp1mx = dp1[x];}
        else if (dp1[x]>dp1mx2) {dp1mx2 = dp1[x];}
    }
    sort(all(dep),greater<>());
    for (int i=0;i<4;i++) {dep.pb(0);}
    mxdep[cur] = dep[0];

    if (k==1) {chmax(ans,dep[0]+dep[1]);}
    else {
        chmax(ans,dp1mx+dp1mx2); // case 1: two dp2
        chmax(dp1[cur],dep[0]+dep[1]); // update dp1
        chmax(dp2[cur],dep[0]+dep[1]+dep[2]); // update dp2

        for (int x : adj[cur]) {
            chmax(dp2[cur],dp1[x]+dep[mxdep[x]+1==dep[0]]);
            
            chmax(ans,dp2[x]+1+dep[mxdep[x]+1==dep[0]]); // case 2: dp2+path
            chmax(ans,dp1[x]+dep[mxdep[x]+1==dep[0]]+dep[1+(mxdep[x]+1==dep[0] || mxdep[x]+1==dep[1])]); // case 3: two paths + dp1
        }

        // case 4: four paths
        chmax(ans,dep[0]+dep[1]+dep[2]+dep[3]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0);
    cout << 2*n-2-ans+k << '\n';
}