#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end() 
#define v vector

v<v<int>> adj;
v<int> e;
int n, q, v1, p;
v<int> path, mx;

bool dfs(int cur, int par) {
    int flag = (cur==v1);
    for (int x : adj[cur]) {
        if (x!=par) {
            flag |= dfs(x,cur);
        }
    }
    if (flag) {path.pb(cur);}
    return flag;
}

void solve() {
    cin >> n >> q;
    e.assign(n,0); adj.assign(n,{});
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    F0R(i,n) {e[i] = adj[i].size()*2-2;} // expected turns until passing this node

    
    while (q--) {
        path.clear(); mx.clear();
        cin >> v1 >> p;
        v1--;
        dfs(0,0); // find path

        for (int i=1;i<path.size()-1;i+=2) {mx.pb(e[path[i]]);} // take every other node
        ll res = path.size()-1;
        sort(all(mx));
        F0R(i,(int)mx.size()-p) {res += mx[i];} // use coins on the P maximum values
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}