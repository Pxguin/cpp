#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define vec vector

const int MAX_N = 2e5;
vec<pii> adj[MAX_N];
map<ll,ll> dist[MAX_N];
ll weight[MAX_N] = {0}, unweight[MAX_N] = {0};
ll ans = INT_MAX;
int k2;

void dfs(int cur, int par) {
    dist[cur][0] = 0;

    for (auto[x,w] : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
            weight[x] += w;
            unweight[x]++;

            if (dist[x].size()>dist[cur].size()) { // small to large merging setup
                swap(dist[x],dist[cur]);
                swap(weight[x],weight[cur]);
                swap(unweight[x],unweight[cur]);
            }
            for (auto[x2,w2] : dist[x]) {
                ll x3 = k2-(x2+weight[x])-weight[cur], w3 = w2+unweight[x];
                if (dist[cur].count(x3)) { // try combining with another path to get length K
                    chmin(ans,dist[cur][x3]+unweight[cur]+w3);
                }
            }
            for (auto[x2,w2] : dist[x]) { // actually merge
                ll x3 = x2+weight[x]-weight[cur], w3 = w2+unweight[x]-unweight[cur];
                if (dist[cur].count(x3)) {
                    chmin(dist[cur][x3],w3);
                } else {
                    dist[cur][x3] = w3;
                }
            }
        }
    }
}

int best_path(int n, int k, int h[][2], int l[]) {
    k2 = k;
    for (int i=0;i<n-1;i++) {
        adj[h[i][0]].pb({h[i][1],l[i]});
        adj[h[i][1]].pb({h[i][0],l[i]});
    }
    dfs(0,0);
    return (ans==INT_MAX ? -1 : ans);
}