#include <bits/stdc++.h>
#include "grader.h"
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define v vector

int n, q;
const int MAX_N = 1e5, l2d = 17;
v<int> adj[MAX_N];
pii pos[MAX_N];
int sz[MAX_N], lift[l2d][MAX_N], dep[MAX_N];

void addRoad(int a, int b) {
    adj[a].pb(b);
    adj[b].pb(a);
}

void dfs(int cur, int par, int d) {
    lift[0][cur] = par; dep[cur] = d; sz[cur] = 1;
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur,d+1);
            sz[cur] += sz[x];
        }
    }
    int cx = -1, cy = -sz[cur];
    for (int x : adj[cur]) {
        if (x!=par) { // organize children diagonally
            pos[x] = {cx,cy+=sz[x]}; // stores delta from the current node (do prefix sums to calc actual position)
            cx -= sz[x];
        }
    }
}
void operator+=(pii& a, pii b) {a.f += b.f; a.s += b.s;}
void dfs2(int cur, int par) {
    for (int x : adj[cur]) { // calculate position of each node
        if (x!=par) {
            pos[x] += pos[cur];
            dfs2(x,cur);
        }
    }
}
void buildFarms() {
    n = getN();
    memset(lift,-1,sizeof(lift));
    dfs(0,-1,0); // calc relative positions (and set up lca calc)
    pos[0] = {n,n};
    dfs2(0,0); // calc absolute positions
    for (int i=0;i<n;i++) {setFarmLocation(i,pos[i].f,pos[i].s);}
    for (int p=1;p<l2d;p++) { // set up bin lift arrays
        for (int i=0;i<n;i++) {
            if (lift[p-1][i]!=-1) {
                lift[p][i] = lift[p-1][lift[p-1][i]];
            }
        }
    }
}

int getpar(int a, int k) { // kth par
    for (int i=l2d-1;i>=0;i--) {
        if ((1<<i)&k) {a = lift[i][a];}
    } return a;
}

void notifyFJ(int a, int b) {
    if (dep[a]<dep[b]) {swap(a,b);}
    int a1 = a, b1 = b;
    a = getpar(a,dep[a]-dep[b]);

    int lca;
    if (a==b) { // lca calc
        lca = a;
    } else {
        for (int i=l2d-1;i>=0;i--) {
            if (lift[i][a]!=lift[i][b]) {
                a = lift[i][a];
                b = lift[i][b];
            }
        } lca = lift[0][a];
    }
    addBox(pos[a1].f,pos[a1].s,pos[lca].f,pos[lca].s); // add (a,lca) and (b,lca) boxes
    if (lca!=b1) {
        lca = getpar(b1,dep[b1]-dep[lca]-1);
        addBox(pos[b1].f,pos[b1].s,pos[lca].f,pos[lca].s);
    }
}