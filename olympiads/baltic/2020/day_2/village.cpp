#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vec vector

const int MAX_N = 1e5;
vec<int> adj[MAX_N];
int n;

namespace MAXIMUM {
    int sz[MAX_N];
    int to[MAX_N]; ll ans = 0;
    int get_size(int cur, int par=-1) {
        sz[cur] = 1;
        for (int x : adj[cur]) {
            if (x!=par) {
                sz[cur] += get_size(x,cur);
            }
        } return sz[cur];
    }
    int get_cent(int cur, int par=-1) {
        for (int x : adj[cur]) {
            if (x!=par) {
                if (sz[x]*2>n) {return get_cent(x,cur);}
            }
        } return cur;
    }
    ll dep_sum(int cur, int par=-1, int dep=0) { // returns 2*depth sum from centroid (which is best answer)
        ll ret = dep*2;
        for (int x : adj[cur]) {
            if (x!=par) {
                ret += dep_sum(x,cur,dep+1);
            }
        } return ret;
    }
    vec<int> ord;
    void dfs(int cur, int par=-1) { // gets preorder traversal
        ord.pb(cur);
        for (int x : adj[cur]) {
            if (x!=par) {dfs(x,cur);}
        }
    }

    void solve() { // get centroid, calculate answer, and make construction
        int cent = get_cent(0,get_size(0));
        get_size(cent);
        ans = dep_sum(cent); dfs(cent);
        for (int i=0;i<n;i++) {to[ord[i]] = ord[(i+n/2)%n];} // a valid construction
    }
}

namespace MINIMUM {
    int to[MAX_N], ans = 0;
    void dfs(int cur, int par=-1) {
        int last = cur; // link parent to first unassigned child
        for (int x : adj[cur]) {
            if (x!=par) {
                dfs(x,cur);
                if (to[x]==-1) { // link previous unassigned child to this unassigned child (create huge cycle)
                    to[last] = x;
                    ans += 2;
                    last = x;
                }
            }
        }
        if (last!=cur) {to[last] = cur;} // link last unassigned child back to parent
        else if (cur==0) { // if root is unassigned, need to assign it
            to[0] = to[adj[cur][0]];
            to[adj[cur][0]] = 0;
            ans += 2;
        }
    }
    void solve() {
        memset(to,-1,sizeof(to));
        dfs(0);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    MINIMUM::solve(); 
    MAXIMUM::solve();
    cout << MINIMUM::ans << ' ' << MAXIMUM::ans << '\n';
    for (int i=0;i<n;i++) {cout << MINIMUM::to[i]+1 << ' ';} cout << '\n';
    for (int i=0;i<n;i++) {cout << MAXIMUM::to[i]+1 << ' ';}
}