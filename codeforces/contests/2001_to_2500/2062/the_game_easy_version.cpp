#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

vec<vec<int>> adj;
int mx[400000], mx2[400000], w[400000];
pii ans;

void dfs(int cur, int par) { // two maximums in the subtree of i (which originate from DIFFERENT children)
    mx[cur] = mx2[cur] = w[cur];
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
            if (mx[x]>=mx[cur]) { // mx and mx2 are two maximums
                mx2[cur] = mx[cur];
                mx[cur] = mx[x];
            } else if (mx[x]>mx2[cur]) {
                mx2[cur] = mx[x];
            }
        }
    }
}
void dfs2(int cur, int par, int m) { // max of node outside subtree of i
    if (m>w[cur]) {chmax(ans,make_pair(w[cur],cur));} // if max > w[i] then it's candidate for answer
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs2(x,cur,max(m,(mx[cur]==mx[x] ? mx2[cur] : mx[cur])));
        }
    }

}

void solve() {
    int n; cin >> n;
    adj.clear(); adj.resize(n);
    ans = {-1,-1};
    F0R(i,n) {cin >> w[i];}

    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0,0);
    dfs2(0,0,-1);
    cout << ans.s+1 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}