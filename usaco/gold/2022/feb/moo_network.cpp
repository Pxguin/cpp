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

ll sq(ll a) {return a*a;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<v<pii>> cows(11);
    F0R(i,n) {
        int x, y; cin >> x >> y;
        cows[y].pb({x,i});
    }
    F0R(i,11) {sort(all(cows[i]));}

    v<pair<ll,pii>> edges;
    F0R(i,11) {
        F0R(j,cows[i].size()) {
            if (j) { // side case (same y-level)
                ll d = sq(cows[i][j].f-cows[i][j-1].f);
                edges.pb({d,{cows[i][j-1].s,cows[i][j].s}});
            }

            F0R(k,11) { // compute closest cows on each y-level for each cow
                int r = lower_bound(all(cows[k]),make_pair(cows[i][j].f,-1LL))-cows[k].begin();
                int l = upper_bound(all(cows[k]),make_pair(cows[i][j].f,-1LL))-cows[k].begin();

                if (r!=cows[k].size()) {
                    ll d = sq(cows[k][r].f-cows[i][j].f)+sq(k-i);
                    edges.pb({d,{cows[k][r].s,cows[i][j].s}});
                }
                if (l) {
                    ll d = sq(cows[k][l-1].f-cows[i][j].f)+sq(k-i);
                    edges.pb({d,{cows[k][l-1].s,cows[i][j].s}});
                }
            }
        }
    } sort(all(edges));

    v<int> par(n), sz(n,1); // kruskal's
    iota(all(par),0);
    
    ll ans = 0;
    auto get = [&](auto& get, int x)->int {return (par[x]==x ? x : par[x]=get(get,par[x]));};
    auto unite = [&](int x, int y) {
        int a = get(get,x), b = get(get,y);
        if (a==b) {return false;}
        if (sz[a]<sz[b]) {swap(a,b);}
        par[b] = a; sz[a] += sz[b];
        return true;
    };
    for (pair<ll,pii> e : edges) {
        if (unite(e.s.f,e.s.s)) {
            ans += e.f;
        }
    } cout << ans << '\n';
}