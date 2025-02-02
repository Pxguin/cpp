#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 200000;
int t[MAX_N], ans[MAX_N], vis[MAX_N];
v<int> rt[MAX_N];

void dfs(int cur) {
    vis[cur] = true;
    for (int x : rt[cur]) {
        if (!vis[x]) {
            ans[x] = ans[cur]+1;
            dfs(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    F0R(i,n) {
        cin >> t[i]; t[i]--;
        rt[t[i]].pb(i);
    }

    F0R(i,n) {
        if (!vis[i]) {
            int x = t[i], y = t[t[i]]; // find cycle
            while (x!=y) {
                x = t[x]; y = t[t[y]];
            }
            v<int> cyc;
            do {
                vis[x] = true;
                cyc.pb(x);
                x = t[x];
            } while (x!=y);
            for (int c : cyc) {ans[c] = cyc.size();} // dfs for cycle
            for (int c : cyc) {dfs(c);}
        } 
    } 
    F0R(i,n) {cout << ans[i] << ' ';}
}