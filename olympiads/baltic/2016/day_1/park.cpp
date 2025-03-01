#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

ll sq(ll x) {return x*x;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, w, h; cin >> n >> m >> w >> h;
    v<pair<pii,int>> trees(n);
    v<int> par(n+4), sz(n+4,1);
    iota(all(par),0);
    F0R(i,n) {cin >> trees[i].f.f >> trees[i].f.s >> trees[i].s;}
    v<pair<int,pii>> edges;
    auto dist = [&](int i, int j) {
        return sqrt((double)(sq(trees[i].f.f-trees[j].f.f)+sq(trees[i].f.s-trees[j].f.s)));
    };
    // n: right n+1: top n+2: left n+3: bottom
    F0R(i,n) { // make edges between borders
        edges.pb({w-trees[i].f.f-trees[i].s,{i,n}});
        edges.pb({trees[i].f.f-trees[i].s,{i,n+2}});
        edges.pb({trees[i].f.s-trees[i].s,{i,n+3}});
        edges.pb({h-trees[i].f.s-trees[i].s,{i,n+1}});
        FOR(j,i+1,n) { // and between trees
            edges.pb({dist(i,j)-trees[i].s-trees[j].s,{i,j}});
        }
    }
    sort(all(edges),greater<>());

    v<pair<pii,int>> vis(m);
    F0R(i,m) {cin >> vis[i].f.f >> vis[i].f.s; vis[i].s = i;}
    sort(all(vis));
    v<array<bool,4>> ans(m); // answer array

    auto get = [&](auto& get, int x)->int {return par[x]==x ? x : par[x]=get(get,par[x]);};
    auto join = [&](int x, int y) {
        int a = get(get,x), b = get(get,y);
        if (a==b) {return;}
        if (sz[a]<sz[b]) {swap(a,b);}
        par[b] = a; sz[a] += sz[b];
    };
    auto diff = [&](int x, int y) {return get(get,x)!=get(get,y);}; // are x and y not connected

    bool hor = true, ver = true; // stores whether these features don't exist
    bool tr = true, tl = true, bl = true, br = true; // hor = chain connecting left & right, tl = chain connecting top and left
    F0R(i,m) {
        int idx = vis[i].s, e = --vis[i].f.s;
        while (edges.size() && edges.back().f<2*vis[i].f.f) { // add edges that this person can't pass through
            join(edges.back().s.f,edges.back().s.s);
            edges.pop_back();
        }
        hor &= diff(n,n+2); ver &= diff(n+1,n+3); // update variables
        tr &= diff(n,n+1); tl &= diff(n+1,n+2);
        bl &= diff(n+2,n+3); br &= diff(n+3,n);
        F0R(j,4) {ans[idx][j] = true;}

        if (e==0) { // casework
            ans[idx][1] &= ver&&br && bl;
            ans[idx][2] &= ver&&hor&&tr && bl;
            ans[idx][3] &= hor&&tl && bl;
        } else if (e==1) {
            ans[idx][2] &= hor&&tr && br;
            ans[idx][3] &= hor&&ver&&tl && br;
            ans[idx][0] &= ver&&bl && br;
        } else if (e==2) {
            ans[idx][3] &= ver&&tl && tr;
            ans[idx][0] &= hor&&ver&&bl && tr;
            ans[idx][1] &= hor&&br && tr;
        } else if (e==3) {
            ans[idx][0] &= hor&&bl && tl;
            ans[idx][1] &= hor&&ver&&br && tl;
            ans[idx][2] &= ver&&tr && tl;
        }
    }
    F0R(i,m) {
        F0R(j,4) {
            if (ans[i][j]) {cout << j+1;}
        } cout << '\n';
    }
}