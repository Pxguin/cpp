#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define vec vector

const int MAX_N = 2e5+1, MAX_C = 10;

struct DSU {
    int par[MAX_N], sz[MAX_N];
    DSU () {
        for (int i=0;i<MAX_N;i++) {
            par[i] = i;
            sz[i] = 1;
        }
    };
    int get(int x) {return par[x]==x ? x : par[x]=get(par[x]);}
    void unite(int x, int y) {
        int a = get(x), b = get(y);
        if (a==b) {return;}
        if (sz[a]<sz[b]) {swap(a,b);}
        sz[a] += sz[b]; par[b] = a;
    }
    bool connected(int x, int y) {return get(x)==get(y);}
};

vec<pii> edges[MAX_C+1];
DSU dsu[MAX_C+1];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, q; cin >> n >> q;
    for (int i=0;i<n-1;i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[c].pb({a,b});
    }
    int ans = 0;
    for (int i=1;i<=MAX_C;i++) { // initial dsu stuff
        dsu[i] = dsu[i-1]; // dsu[i] = state of the graph after process all edges with weight <= i
        for (pii e : edges[i]) {
            dsu[i].unite(e.f,e.s);
            ans += i;
        }
    }
    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        if (!dsu[c].connected(a,b)) { // if a and b aren't connected in dsu[c] then connect them
            dsu[c].unite(a,b);
            ans += c; // so include this edge in the mst
            for (int i=c+1;i<=MAX_C;i++) {
                if (dsu[i].connected(a,b)) { // and the weight of the edge to remove is the first dsu such that a and b are connected
                    ans -= i; break;
                } else {dsu[i].unite(a,b);}
            }
        }
        cout << ans << '\n';
    }
}