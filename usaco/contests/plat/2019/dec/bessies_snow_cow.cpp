#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 1e5+2;
struct BIT {
    ll b[MAX_N] = {0};
    void add(int i, ll a) {
        for (;i<MAX_N;i+=i&-i) {b[i] += a;}
    }
    ll sum(int i) {
        ll res = 0;
        for (;i;i-=i&-i) {res += b[i];}
        return res;
    }
};

v<int> adj[MAX_N];
int tin[MAX_N], tout[MAX_N], timer = 1;

struct cmp {
    bool operator()(const int& a, const int& b) const {
        return tin[a]<tin[b];
    }
};

set<int,cmp> colors[MAX_N];

void dfs(int cur, int par) {
    tin[cur] = timer++;
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
        }
    }
    tout[cur] = timer-1;
}

BIT b1, b2;

void add_range(int l, int r, ll a) { // range update on BIT by a
    b1.add(l,a);
    b1.add(r+1,-a);
    b2.add(l,a*(l-1));
    b2.add(r+1,-a*r);
}
ll query(ll l, ll r) { // range query on BIT
    return (b1.sum(r)*r-b2.sum(r))-(b1.sum(l-1)*(l-1)-b2.sum(l-1));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("snowcow.in","r",stdin);
    freopen("snowcow.out","w",stdout);

    int n, q; cin >> n >> q;
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0,0);

    while (q--) {
        int t; cin >> t;
        if (t==1) {
            int c, x; cin >> x >> c; 
            c--; x--;

            auto it2 = colors[c].upper_bound(x);
            if (it2==colors[c].begin() || tout[*prev(it2)]<tin[x]) { // check if no range contains this
                auto it = colors[c].lower_bound(x);
                while (it!=colors[c].end() && tout[*it]<=tout[x]) { // if so then delete all ranges this contains
                    add_range(tin[*it],tout[*it],-1); // update BITs
                    it = colors[c].erase(it);
                }
                colors[c].insert(x); // insert this range in and update BITs
                add_range(tin[x],tout[x],1);
            } 
        } else {
            int x; cin >> x; x--;
            cout << query(tin[x],tout[x]) << '\n'; // query
        }
    }
}