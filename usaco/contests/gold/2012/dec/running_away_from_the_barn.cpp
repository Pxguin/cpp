#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,ll>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 200000, l2d = 18;
ll par[l2d][MAX_N], mn[l2d][MAX_N];
ll dist[MAX_N];
v<pii> adj[MAX_N];
ll ans[MAX_N] = {0};
ll l;

void dfs(int cur, int p, ll d, int d2) { // get initial values
    par[0][cur] = p;
    dist[cur] = d;
    if (p!=-1) {mn[0][cur] = dist[p];}

    for (pii x : adj[cur]) {
        dfs(x.f,cur,d+x.s,d2+1);
    }
}

void ans_dfs(int cur) {
    for (pii x : adj[cur]) {
        ans_dfs(x.f);
        ans[cur] += ans[x.f]; // calc answer
    }
}

void find(int x) {
    int x2 = x;
    ll goal = dist[x]-l; // find last node with dist >= goal ie first dist<goal
    for (int i=l2d-1;i>=0;i--) {
        if (par[i][x]==-1) {continue;}
        if (mn[i][x]>=goal) {x = par[i][x];} // recursively break down range just like segment tree
    }
    ans[x2]++; // set prefix sum stuff
    if (x!=0) {ans[par[0][x]]--;}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("runaway.in","r",stdin);
    freopen("runaway.out","w",stdout);

    int n; cin >> n >> l;
    F0R(i,n-1) {
        ll l1, p1; cin >> p1 >> l1;
        adj[--p1].pb({i+1,l1});
    }

    memset(par,-1,sizeof(par));
    F0R(p,l2d) {F0R(i,n) {mn[p][i] = LLONG_MAX;}}
    dfs(0,-1,0,0);

    FOR(p,1,l2d) { // complete binary jump arrays
        F0R(i,n) {
            if (par[p-1][i]!=-1 && par[p-1][par[p-1][i]]!=-1) {
                par[p][i] = par[p-1][par[p-1][i]];
                mn[p][i] = mn[p-1][par[p-1][i]];
            }
        }
    }
    
    F0R(i,n) { // find earliest node <= distance L away
        find(i);
    }
    ans_dfs(0);
    F0R(i,n) {cout << ans[i] << '\n';}
}