#include <bits/stdc++.h>
#include "dreaming.h"
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define vec vector

const int MAX_N = 1e5;
vec<pii> adj[MAX_N];
int dist[MAX_N];
bool vis[MAX_N];
pii cent[MAX_N];

pii furthest(int cur, int par=-1, int len=0) { // furthest distance + furthest node
    vis[cur] = true;
    pii mx = {len,cur};
    for (auto[x,w] : adj[cur]) {
        if (x!=par) {
            chmax(mx,furthest(x,cur,len+w));
        }
    } return mx;
}

int travelTime(int n, int m, int l, int a[], int b[], int t[]) {
    for (int i=0;i<m;i++) {
        adj[a[i]].pb({b[i],t[i]});
        adj[b[i]].pb({a[i],t[i]});
    }

    memset(vis,0,sizeof(vis));
    memset(dist,-1,sizeof(dist));
    pii rt = {0,0};

    int c = 0;
    for (int i=0;i<n;i++) {
        if (!vis[i]) {
            int d1 = furthest(i).s, d2 = furthest(d1).s; // compute diameter of tree

            queue<pair<int,pii>> q;
            cent[c] = {INT_MAX,0};
            q.push({d1,{-1,0}}); q.push({d2,{-1,0}});
            while (q.size()) { // compute center of tree
                auto[cur,z] = q.front(); q.pop();
                auto[par,len] = z;
                if (dist[cur]!=-1) {
                    chmin(cent[c],mp(max(len,dist[cur]),cur));
                }
                dist[cur] = len;
                for (auto[x,w] : adj[cur]) {
                    if (x!=par) {
                        q.push({x,{cur,len+w}});
                    }
                }
            }
            chmax(rt,cent[c]);
            c++;
        }
    }
    for (int i=0;i<c;i++) {
        if (cent[i]!=rt) { // connect all centers to center with maximum min dist
            adj[cent[i].s].pb({rt.s,l});
            adj[rt.s].pb({cent[i].s,l});
        }
    }
    return furthest(furthest(0).s).f; // compute diameter of new tree
}