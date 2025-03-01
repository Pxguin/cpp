#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define v vector

const int MAX_N = 3e5;
v<int> adj[MAX_N];
v<int> path;
int a, b;

bool find_path(int cur, int par) { // find path from a to b
    for (int x : adj[cur]) {
        if (x!=par) {
            path.pb(x);
            if (find_path(x,cur)) {
                return true;
            } else {
                path.pop_back();
            }
        }
    }
    return (cur==b);
}

int dfs(int cur, int par, int p) { // calculates min time for one source
    v<int> dp;
    for (int x : adj[cur]) {
        if (x!=par && x!=p) {
            dp.pb(dfs(x,cur,p));
        }
    }
    int ret = 0;
    sort(all(dp),greater<>()); // optimal order to visit nodes
    for (int i=0;i<dp.size();i++) {
        ret = max(ret,dp[i]+i+1);
    }
    return ret;
}

pair<int,int> check(int p) {
    return make_pair(dfs(a,-1,path[p]),dfs(b,-1,path[p-1]));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n >> a >> b;
    a--; b--;
    path.pb(a);

    for (int i=0;i<n-1;i++) {
        int c, d; cin >> c >> d;
        adj[--c].pb(--d);
        adj[d].pb(c);
    }

    find_path(a,-1);

    int lo = 1, hi = path.size()-1, mid = (lo+hi)/2, ans = path.size()-1;
    while (lo <= hi) { // binary search on first edge broken such that cost for A >= cost for B (let this be M)
        pii res = check(mid);
        if (res.f >= res.s) {
            ans = mid;
            hi = mid-1;
        } else {lo = mid+1;}
        mid = (lo+hi)/2;
    }

    pii cand1 = check(ans), cand2 = (ans==0 ? make_pair(INT_MAX,INT_MAX) : check(ans-1)); // candidates for answer are edges M and M-1
    cout << min(max(cand1.f,cand1.s),max(cand2.f,cand2.s)) << '\n';
}