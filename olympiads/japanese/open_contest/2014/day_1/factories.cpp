#include <bits/stdc++.h>
#include "factories.h"
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

const int N = 5e5;
int sz[N];
bool del[N] = {false};
vec<pair<int,int>> adj[N];
vec<pair<int,ll>> anc[N];
ll dist[N];

int upd_sizes(int cur, int par=-1) {
    sz[cur] = 1;
    for (auto[x,w] : adj[cur]) {
        if (x!=par && !del[x]) {
            sz[cur] += upd_sizes(x,cur);
        }
    }
    return sz[cur];
}
int find_cent(int cur, int n2, int par=-1) {
    for (auto[x,w] : adj[cur]) {
        if (x!=par && !del[x]) {
            if (sz[x]>n2/2) {return find_cent(x,n2,cur);}
        }
    } return cur;
}
void upd_dist(int cur, int cent, ll d, int par=-1) {
    anc[cur].pb({cent,d});
    for (auto[x,w] : adj[cur]) {
        if (x!=par && !del[x]) {
            upd_dist(x,cent,d+w,cur);
        }
    }
}
void decomp(int cur=0) {
    int cent = find_cent(cur,upd_sizes(cur));
    del[cent] = true;
    for (auto[x,w] : adj[cent]) {
        if (!del[x]) {
            upd_dist(x,cent,w);
        }
    } anc[cent].pb({cent,0});
    for (auto[x,w] : adj[cent]) {
        if (!del[x]) {
            decomp(x);
        }
    }
}

void Init(int n, int a[], int b[], int d[]) {
    for (int i=0;i<n-1;i++) {
        adj[a[i]].pb({b[i],d[i]});
        adj[b[i]].pb({a[i],d[i]});
    }
    decomp();
    for (int i=0;i<n;i++) {dist[i] = 1e18;}
}

ll Query(int s, int x[], int t, int y[]) {
    for (int i=0;i<s;i++) {
        for (auto[c,w] : anc[x[i]]) {chmin(dist[c],w);}
    }
    ll ans = 1e18;
    for (int i=0;i<t;i++) {
        for (auto[c,w] : anc[y[i]]) {chmin(ans,w+dist[c]);}
    }

    for (int i=0;i<s;i++) {
        for (auto[c,w] : anc[x[i]]) {dist[c] = 1e18;}
    }
    return ans;
}