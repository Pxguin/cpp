#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

stack<int> toposort;
v<set<int>> adj;
set<int> unvis;

void dfs(int cur) {
    auto it = unvis.upper_bound(cur);
    while (it!=unvis.end()) {
        if (adj[cur].count(*it)) {it++;}
        else {
            int x = *it;
            unvis.erase(it);
            dfs(x);
            it = unvis.upper_bound(x);
        }
    } toposort.push(cur);
}

void solve() {
    int n, m; cin >> n >> m;
    adj.clear(); adj.resize(n);
    F0R(i,n) {unvis.insert(i);}

    F0R(i,m) {
        int a, b; cin >> a >> b;
        adj[--a].insert(--b);
    }
    
    F0R(i,n) {
        if (unvis.count(i)) {
            unvis.erase(i);
            dfs(i);
        }
    }
    while (toposort.size()) {cout << toposort.top()+1 << ' '; toposort.pop();}
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}