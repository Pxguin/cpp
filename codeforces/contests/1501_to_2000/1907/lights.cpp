#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vec vector

const int N = 1e5;
int to[N];
vec<int> radj[N];
bool on[N], vis[N];
vec<int> ans;

void dfs(int cur) { // make all lights in subtree off
    vis[cur] = true;
    for (int x : radj[cur]) {
        if (!vis[x]) {
            dfs(x);
            if (on[x]) { // if child is on, turn off child
                on[cur] = !on[cur];
                ans.pb(x);
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        char c; cin >> c;
        on[i] = (c=='1');

        radj[i].clear();
    }

    for (int i=0;i<n;i++) {
        cin >> to[i]; to[i]--;
        radj[to[i]].pb(i);
    }
    
    ans.clear();
    fill(vis,vis+n,false);
    bool flag = false;
    for (int i=0;i<n;i++) {
        if (!vis[i]) {
            int p1 = to[i], p2 = to[p1];
            while (p1!=p2) { // find cycles
                p1 = to[p1];
                p2 = to[to[p2]];
            }

            vec<int> cyc, states;
            do { // find cycles
                cyc.pb(p2);
                p2 = to[p2];
                vis[p2] = true;
            } while (p1!=p2);

            for (int x : cyc) {dfs(x); states.pb(on[x]);} // (ignoring cycle) dfs from each node in cycle
            for (int x : cyc) { // find a node that is still on
                if (on[to[x]]) {p1 = x;}
            }

            auto doit = [&](int cur, bool z) {
                for (int i=0;i<cyc.size();i++) { // reset all states back to original
                    vis[cyc[i]] = false;
                    on[cyc[i]] = states[i];
                }
                int sz = ans.size();
                dfs(cur); // do a dfs
                int ret = ans.size();
                if (z) { // reset answer
                    while (ans.size()>sz) {ans.pop_back();}
                }
                return (on[cur] ? INT_MAX : ret); // return the cost
            };
            p1 = (doit(p1,true)<doit(to[p1],true) ? p1 : to[p1]); // try not using either edge adjacent to the node in the cycle
            doit(p1,false); // take the better option (minimizes cost)
            if (on[p1]) {flag = true;} // fail case (not all lights are off still)
        }
    }
    if (flag) {cout << -1 << '\n';}
    else {
        cout << ans.size() << '\n';
        for (int x : ans) {cout << x+1 << ' ';} cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}