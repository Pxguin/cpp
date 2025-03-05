#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 5e5+2, l2d = 21;
pii st[l2d][2*MAX_N];
v<pii> euler;

int c[MAX_N];
v<int> adj[MAX_N];
int bit[MAX_N] = {0}, tin[MAX_N], tintour[MAX_N], tout[MAX_N], timer = 1;

int log2(int i) {return __builtin_clz(1)-__builtin_clz(i);}
int lca(int a, int b) { // literally all precalculation for lca
    if (tintour[a]>tintour[b]) {swap(a,b);}
    int l = log2(tintour[b]-tintour[a]+1);
    return min(st[l][tintour[a]],st[l][tintour[b]-(1<<l)+1]).s;
}

void add(int i, int a) { // fenwick tree
    for (;i<MAX_N;i+=i&-i) {bit[i] += a;}
}
int sum(int i) {
    int res = 0;
    for (;i;i-=i&-i) {res += bit[i];}
    return res;
}

void dfs(int cur, int par, int d) { // and euler tur
    tin[cur] = timer++;
    tintour[cur] = euler.size();
    euler.pb({d,cur});
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur,d+1);
            euler.pb({d,cur});
        }
    }
    tout[cur] = timer;
}

void upd(set<int>::iterator it, int a) { // helpful function for adding to the lca in the fenwick tree
    add(tin[lca(*it,*next(it))],a);
}
struct cmp {
    bool operator()(const int& a, const int& b) const {return tin[a]<tin[b];}
};
set<int,cmp> grp[MAX_N]; // groups nodes by color

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, useless, m; cin >> n >> useless >> m;
    F0R(i,n) {cin >> c[i];}
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0,-1,0);

    F0R(i,euler.size()) {st[0][i] = euler[i];} // euler tour & lca precalc
    FOR(b,1,l2d) {
        for (int i=0;i+(1<<b)<=euler.size();i++) {
            st[b][i] = min(st[b-1][i],st[b-1][i+(1<<(b-1))]);
        }
    }
    F0R(i,n) {grp[--c[i]].insert(i);}
    
    F0R(i,n) { // for each adjacent pairs of nodes in each group, subtract 1 from all nodes on path from lca to root
        if (grp[i].empty()) {continue;}
        for (auto it=grp[i].begin();it!=prev(grp[i].end());it++) {
            upd(it,1);
        }
    }

    while (m--) {
        int t; cin >> t;
        if (t==1) {
            int x, k; cin >> x >> k; x--; k--;
            auto it = grp[c[x]].find(x);

            if (it!=grp[c[x]].begin()) {upd(prev(it),-1);} // erase from the previous group, update lca as necessary
            if (it!=prev(grp[c[x]].end())) {upd(it,-1);}
            it = grp[c[x]].erase(it);
            if (it!=grp[c[x]].begin() && it!=grp[c[x]].end()) {upd(prev(it),1);}


            c[x] = k; // add to new group, update lca
            it = grp[k].lower_bound(x);
            if (it!=grp[k].begin() && it!=grp[k].end()) {upd(prev(it),-1);}

            it = grp[k].insert(x).f;
            if (it!=grp[k].begin()) {upd(prev(it),1);}
            if (it!=prev(grp[k].end())) {upd(it,1);}

        } else {
            int k; cin >> k; k--;
            cout << (tout[k]-tin[k])-(sum(tout[k]-1)-sum(tin[k]-1)) << '\n'; // size of group minus number of distinct values
        }
    }
}