#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define v vector

const int MAX_N = 2e5+1;
ll bit[MAX_N+1];
void add(int i, ll a) { // fenwick tree
    for (;i<=MAX_N;i+=(i&-i)) {
        bit[i] += a;
    }
}
ll sum(int i) {
    ll res = 0;
    for(;i;i-=(i&-i)) {res += bit[i];}
    return res;
}

int tin[MAX_N], tout[MAX_N], val[MAX_N];
v<int> adj[MAX_N];
void dfs(int cur, int par) {
    tout[cur] = tin[cur];
    for (int x : adj[cur]) {
        if (x!=par) {
            tin[x] = tout[cur]+1; // tin/tout for euler tour
            dfs(x,cur);
            tout[cur] = tout[x];
        }
    }
    add(tin[cur],val[cur]); // update subtre
    add(tout[cur]+1,-val[cur]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;
    for (int i=0;i<n;i++) {cin >> val[i];}
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    tin[0] = 1;
    dfs(0,0);

    while (q--) {
        int t; cin >> t;
        if (t==1) {
            int s, x; cin >> x >> s; x--;
            add(tin[x],-val[x]); // remove old value
            add(tout[x]+1,val[x]);
            val[x] = s; // set new value
            add(tin[x],val[x]);
            add(tout[x]+1,-val[x]);
        } else {
            int x; cin >> x; x--;
            cout << sum(tin[x]) << '\n'; // range sum
        }
    }
}