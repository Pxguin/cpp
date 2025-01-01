#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int n, t;
const int MAX_N = 2e5;
v<int> adj[MAX_N];
int a[MAX_N], sz[MAX_N];
ll sum[MAX_N];
pii dp_t[MAX_N], dp_c[MAX_N];


void dfs(int cur) {
    sz[cur] = 1;
    sum[cur] += a[cur];

    for (int x : adj[cur]) {
        dfs(x);
        sz[cur] += sz[x];
        sum[cur] += sum[x];
    }
    dp_t[cur].f = dp_t[cur].s = sz[cur]*2-2;
    if (sz[cur]==1) {return;}

    sort(all(adj[cur]),[&](int a, int b) {
        if (dp_t[a].f-dp_t[a].s==dp_t[b].f-dp_t[b].s) { // sort by time saved
            return sz[a]*sum[b]<sz[b]*sum[a]; // if it's the same, sort by sz/sum
        } return dp_t[a].f-dp_t[a].s<dp_t[b].f-dp_t[b].s;
    });

    int cut = adj[cur].back();
    sort(all(adj[cur]),[&](int a, int b) {return sz[a]*sum[b]<sz[b]*sum[a];});

    dp_t[cur].s -= dp_t[cut].f-dp_t[cut].s+1; // calc min time T=1

    v<ll> ps(1,0), ss(adj[cur].size()+1,0);
    ll tot1 = 0; // setup to calc min cost T=0
    for (int x : adj[cur]) {
        dp_c[cur].f += dp_c[x].f+sum[x]*(1+tot1); 
        tot1 += sz[x]*2;
        ps.pb(dp_c[cur].f);
    }
    
    // trying something new...
    dp_c[cur].s = LLONG_MAX;
    for (int i=adj[cur].size()-1;i>=0;i--) {
        ss[i] = ss[i+1]+sum[adj[cur][i]];
    }
    F0R(i,adj[cur].size()) {
        int c = adj[cur][i];
        if (dp_t[c].f-dp_t[c].s==dp_t[cut].f-dp_t[cut].s) { // if it minimizes the time, try moving it to the back
            ll term = dp_c[cur].f-ss[i+1]*2*sz[c] - (ps[i+1]-ps[i]);
            term += (tot1-sz[c]*2+1)*sum[c]+dp_c[c].s;
            dp_c[cur].s = min(dp_c[cur].s,term);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> t;
    F0R(i,n-1) {
        int p; cin >> p >> a[i+1];
        adj[--p].pb(i+1);
    }

    dfs(0);
    if (t==0) {cout << dp_t[0].f << ' ' << dp_c[0].f << '\n';}
    else {cout << dp_t[0].s << ' ' << dp_c[0].s << '\n';}
}