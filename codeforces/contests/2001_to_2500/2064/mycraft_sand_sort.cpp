#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

ll mod = 998244353;

struct DSU {
    v<int> par, sz;
    DSU (int n) : par(v<int>(n)), sz(v<int>(n,1)) {
        F0R(i,n) {par[i] = i;}
    }
    int get(int x) {return (par[x]==x ? x : par[x]=get(par[x]));}
    void join(int x, int y) {
        int a = get(x), b = get(y);
        if (a!=b) {
            if (sz[a]<sz[b]) {swap(a,b);}
            sz[a] += sz[b]; par[b] = a;
        }
    }

};

void solve() {
    int n; cin >> n;
    v<int> p(n), c(n);
    v<int> from(n,-1), to(n,-1);

    F0R(i,n-1) {from[i] = i+1; to[i+1] = i;}

    F0R(i,n) {
        int x; cin >> x;
        p[--x] = i;
    }
    DSU dsu(n);
    F0R(i,n) {
        cin >> c[i];
        if (i && c[i]==c[i-1]) {dsu.join(i,i-1);}
    }
    ll ans = 1;
    F0R(i,n) { // iterate over which block is removed
        int block = p[i], above = from[block], below = to[block];
        ans = ans*(dsu.sz[dsu.get(block)])%mod; // multiply answer by the size of its component
        dsu.sz[dsu.get(block)]--; // remove this block so subtract 1 from component size

        if (above!=-1 && below!=-1 && c[above]==c[below]) {dsu.join(above,below);} // find adjacent blocks and merge is possible
        if (above!=-1) {to[above] = below;} // update dll because we delete this block
        if (below!=-1) {from[below] = above;}
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}