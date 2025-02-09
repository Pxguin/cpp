#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

struct DSU {
    v<int> par, sz;
    int n;
    DSU (int n) : n(n), sz(v<int>(n,1)) {F0R(i,n) {par.pb(i);}};
    int get(int x) {return par[x]==x ? x : par[x]=get(par[x]);}
    void merge(int x, int y) {
        int a = get(x), b = get(y);
        if (a==b) {return;}
        if (sz[a]<sz[b]) {swap(a,b);}
        par[b] = a; sz[a] += sz[b];
    }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    int n, k, l; cin >> n >> k >> l;
    DSU road(n), rail(n), ans(n);
    F0R(i,k) {
        int a, b; cin >> a >> b;
        road.merge(--a,--b);
    }
    F0R(i,l) {
        int a, b; cin >> a >> b;
        rail.merge(--a,--b);
    }
    v<v<int>> c(n);
    F0R(i,n) {c[road.get(i)].pb(i);}
    F0R(i,n) {
        map<int,int> to;
        for (int x : c[i]) {
            if (to.count(rail.get(x))) {
                ans.merge(to[rail.get(x)],x);
            } to[rail.get(x)] = x;
        }
    }
    F0R(i,n) {cout << ans.sz[ans.get(i)] << ' ';}
}