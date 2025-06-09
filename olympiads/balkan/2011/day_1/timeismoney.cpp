#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second

const int MAX_N = 200, MAX_M = 10000;

struct DSU {
    int par[MAX_N], sz[MAX_N];

    int get(int x) {return par[x]==x ? x : par[x]=get(par[x]);}
    bool unite(int a, int b) {
        a = get(a); b = get(b);
        if (a==b) {return false;}
        if (sz[a]<sz[b]) {swap(a,b);}
        par[b] = a; sz[a] += sz[b];
        return true;
    }

    void reset() {
        iota(par,par+MAX_N,0);
        memset(sz,1,sizeof(sz));
    }
};

struct Edge {
    int u, v, t, c;
    ll w;
    bool operator<(const Edge& o) const {return w<o.w;}
};
Edge ed[MAX_M];
DSU dsu;
ll c_ans = 1e9, t_ans = 1e9, c_tot, t_tot;
Edge ans[MAX_N], cand[MAX_N];
int n, m;

void calc() {
    dsu.reset();
    sort(ed,ed+m);
    c_tot = 0, t_tot = 0;
    for (int i=0,ptr=0;i<m;i++) {
        if (dsu.unite(ed[i].u,ed[i].v)) {
            cand[ptr++] = ed[i];
            c_tot += ed[i].c; t_tot += ed[i].t;
            if (ptr==n-1) {break;}
        }
    } if (c_tot*t_tot<c_ans*t_ans) {
        c_ans = c_tot; t_ans = t_tot;
        copy(cand,cand+n-1,ans);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i=0;i<m;i++) {cin >> ed[i].u >> ed[i].v >> ed[i].t >> ed[i].c;}

    stack<pair<pii,pii>> todo;
    for (int i=0;i<m;i++) {ed[i].w = ed[i].t;}
    calc();
    pii a0 = {t_tot,c_tot};
    
    for (int i=0;i<m;i++) {ed[i].w = ed[i].c;}
    calc();
    pii b0 = {t_tot,c_tot};

    todo.push({a0,b0});
    while (todo.size()) {
        auto[a,b] = todo.top(); todo.pop();
        for (int i=0;i<m;i++) {ed[i].w = (ll)(a.s-b.s)*ed[i].t+(ll)(b.f-a.f)*ed[i].c;}

        calc();
        pii c = {t_tot,c_tot};
        if ((ll)(b.f-a.f)*(c.s-a.s)-(ll)(b.s-a.s)*(c.f-a.f)<0) {
            todo.push({a,c});
            todo.push({c,b});
        }
    }
    cout << t_ans << ' ' << c_ans << '\n';
    for (int i=0;i<n-1;i++) {cout << ans[i].u << ' ' << ans[i].v << '\n';}
}