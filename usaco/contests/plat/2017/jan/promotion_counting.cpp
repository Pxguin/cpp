#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 1e5+2, l2d = 18;
int bit[MAX_N] = {0};
void add(int i) {
    for (;i<MAX_N;i+=i&-i) {bit[i]++;}
}
int get(int i) {
    int res = 0;
    for (;i;i-=i&-i) {res += bit[i];}
    return res;
}

int tin[MAX_N], tout[MAX_N], ans[MAX_N];
pii p[MAX_N];
int timer = 1;
v<int> adj[MAX_N];

void dfs(int cur, int par) {
    tin[cur] = timer++;
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
        }
    }
    tout[cur] = timer-1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("promote.in","r",stdin);
    freopen("promote.out","w",stdout);

    int n; cin >> n;
    F0R(i,n) {cin >> p[i].f; p[i].s = i;}
    F0R(i,n-1) {
        int a; cin >> a;
        adj[i+1].pb(--a);
        adj[a].pb(i+1);
    }
    dfs(0,0);
    sort(p,p+n,greater<>()); // process cows by decreasing proficiency

    F0R(i,n) {
        ans[p[i].s] = get(tout[p[i].s])-get(tin[p[i].s]); // sum up # of processed cows in its subtree

        add(tin[p[i].s]);
    }
    F0R(i,n) {cout << ans[i] << '\n';}
}