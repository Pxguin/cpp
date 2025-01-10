#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m, k; cin >> n >> m >> k;
    v<pair<int,pii>> edges;

    F0R(i,m) {
        int u, v, w; cin >> u >> v >> w;
        edges.pb({w,{--u,--v}});
    } sort(all(edges));
    
    v<int> sz(n,1), par(n);
    v<pii> ab(n,{0,0});
    iota(all(par),0);

    F0R(i,k) {
        int a; cin >> a;
        ab[--a].f++;
    }
    F0R(i,k) {
        int b; cin >> b;
        ab[--b].s++;
    }


    ll cur = 0, ans = 0;
    auto get = [&](auto& get, int x)->int {return (par[x]==x ? x : par[x]=get(get,par[x]));};
    auto merge = [&](int x, int y) {
        int a = get(get,x), b = get(get,y);
        if (a==b) {return;}
        if (sz[a]>sz[b]) {swap(a,b);}

        ab[b].f += ab[a].f; ab[b].s += ab[a].s; // pair up as many as possible
        int sub = min(ab[b].f,ab[b].s);
        ans += cur*sub;
        ab[b].f -= sub; ab[b].s -= sub;

        sz[b] += sz[a];
        par[a] = b;
    };

    for (auto e : edges) {
        cur = e.f;
        merge(e.s.f,e.s.s);
    }
    cout << ans << '\n';
}