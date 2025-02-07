#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 200000;
int c[MAX_N], q[MAX_N];
ll in[MAX_N], num[MAX_N], out[MAX_N];
int ch = 0;
ll ans = LLONG_MAX;

v<pii> adj[MAX_N];

void dfs(int cur, int par) {
    if (c[cur]==ch) {num[cur] = q[cur];}
    for (pii x : adj[cur]) {
        if (x.f!=par) {
            dfs(x.f,cur);
            in[cur] += in[x.f]+num[x.f]*x.s; // add (# flowers of this type * road length)
            num[cur] += num[x.f];
        }
    }
}
void dfs2(int cur, int par) {
    chmin(ans,out[cur]+in[cur]);
    for (pii x : adj[cur]) {
        if (x.f!=par) {
            ll cont = in[x.f]+num[x.f]*x.s; // cost is (total cost for par excluding this subtree) + (# flowers outside subtree * road len)
            out[x.f] = (out[cur]+in[cur]-cont)+(num[0]-num[x.f])*x.s;
            dfs2(x.f,cur);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    
    F0R(i,n) {
        char c1; cin >> c1; 
        c[i] = c1-'a';
    }
    F0R(i,n) {cin >> q[i];}
    F0R(i,n-1) {
        int a, b, d; cin >> a >> b >> d;
        adj[--a].pb({--b,d});
        adj[b].pb({a,d});
    }
    for (;ch<26;ch++) {
        memset(in,0,sizeof(in));
        memset(num,0,sizeof(num));
        memset(out,0,sizeof(out));
        ans = LLONG_MAX;
        dfs(0,0); // calc inside subtree distance
        dfs2(0,0); // calc outside subtree distance
        cout << (ans==LLONG_MAX ? 0 : ans) << ' ';
    }
}