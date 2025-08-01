#include <bits/stdc++.h>
using namespace std;

/*
Solution:
For each portal i compute minimum cost to get to (e_i,x_i) i.e. use that portal

Portals used have decreasing S so process in that order and use centroid decomp + priority queues to get min cost

For query i: only consider portals j with e_j<=s_i so sort portals by increasing E, queries by increasing S,
and do centroid decomp

O((N+Q)logN+Mlog^2N)
*/

#define ll long long
#define pb push_back
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define vec vector

struct Portal {
    int x, second, e, w;
    ll mn_time = 1e18;
};
bool cmp1(const Portal& a, const Portal& b) {return a.s>b.s;}
bool cmp2(const Portal& a, const Portal& b) {return a.e<b.e;}

using T = pair<ll,int>;
const int N = 1e5;
vec<pair<int,ll>> adj[N];
vec<pair<int,ll>> anc[N];
priority_queue<T,vec<T>,greater<T>> mn_dist[N];
ll mn_dist2[N];

Portal p[N+1], qry[N];
ll ans[N];

namespace centroid {
    int sz[N];
    bool del[N] = {false};
    int get_sizes(int cur, int par=-1) {
        sz[cur] = 1;
        for (auto[x,w] : adj[cur]) {
            if (!del[x] && x!=par) {
                sz[cur] += get_sizes(x,cur);
            }
        } return sz[cur];
    }
    int get_cent(int cur, int n, int par=-1) {
        for (auto[x,w] : adj[cur]) {
            if (!del[x] && x!=par) {
                if (sz[x]*2>n) {return get_cent(x,n,cur);}
            }
        } return cur;
    }
    void upd_dist(int cur, int cent, int par=-1, ll d=0) {
        anc[cur].pb({cent,d});
        for (auto[x,w] : adj[cur]) {
            if (x!=par && !del[x]) {
                upd_dist(x,cent,cur,d+w);
            }
        }
    }

    void decomp(int cur=0) {
        int cent = get_cent(cur,get_sizes(cur));
        del[cent] = true;
        upd_dist(cent,cent);

        for (auto[x,w] : adj[cent]) {
            if (!del[x]) {decomp(x);}
        }
    }
}

void upd(int cur, int time, ll wei) {
    for (auto[x,w] : anc[cur]) {
        mn_dist[x].push({wei+w,time});
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, q, t; cin >> n >> m >> q >> t;
    for (int i=0;i<n-1;i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b,c}); adj[b].pb({a,c});
    }
    
    for (int i=0;i<m;i++) {
        cin >> p[i].x >> p[i].s >> p[i].e >> p[i].w;
    } sort(p,p+m,cmp1);

    centroid::decomp();
    upd(0,t,0);
    for (int i=0;i<m;i++) {
        for (auto[x,w] : anc[p[i].x]) {
            while (mn_dist[x].size() && mn_dist[x].top().s>p[i].s) {mn_dist[x].pop();}
            if (mn_dist[x].size()) {chmin(p[i].mn_time,mn_dist[x].top().f+w+p[i].w);}
        }
        upd(p[i].x,p[i].e,p[i].mn_time);
    }
    p[m] = (Portal){0,0,t,0,0};

    fill(mn_dist2,mn_dist2+n,1e18);
    fill(ans,ans+q,1e18);
    sort(p,p+m+1,cmp2);
    for (int i=0;i<q;i++) {
        cin >> qry[i].e >> qry[i].s; qry[i].x = i;
    }
    sort(qry,qry+q,cmp2);

    for (int i=0,ptr=0;i<q;i++) {
        while (ptr!=m+1 && p[ptr].e<=qry[i].e) {
            for (auto[x,w] : anc[p[ptr].x]) {
                chmin(mn_dist2[x],w+p[ptr].mn_time);
            } ptr++;
        }
        for (auto[x,w] : anc[qry[i].s]) {
            chmin(ans[qry[i].x],w+mn_dist2[x]);
        }
    }
    for (int i=0;i<q;i++) {cout << (ans[i]==1e18 ? -1 : ans[i]) << '\n';} 
}