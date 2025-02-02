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

void solve(int t) {
    int n; cin >> n;
    v<pair<int,pii>> edges;

    int c;
    F0R(i,n) {
        F0R(j,n) {cin >> c;}
    }

    int tot = 0;
    F0R(i,n) {
        F0R(j,n) {
            cin >> c;
            edges.pb({c,{i,j+n}}); // make edge between row and column
            tot += c;
        }
    } sort(all(edges),greater<>());
    F0R(i,2*n) {cin >> c;}

    v<int> par(2*n), sz(2*n,1);
    iota(all(par),0);

    auto get = [&](auto& get, int x)->int {return (par[x]==x ? x : par[x]=get(get,par[x]));};
    auto unite = [&](int x, int y) {
        int a = get(get,x), b = get(get,y);
        if (a==b) {return false;}
        if (sz[a]<sz[b]) {swap(a,b);}
        sz[a] += sz[b]; par[b] = a;
        return true;
    };
    for (pair<int,pii> e : edges) { // find max spanning tree
        if (unite(e.s.f,e.s.s)) {tot -= e.f;}
    } cout << "Case #" << t << ": " << tot << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    F0R(i,t) {solve(i+1);}
}