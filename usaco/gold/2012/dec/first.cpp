#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

bool adj[30000][26][26];
bool vis[26], stk[26], flag = false;

void dfs(int i, int j) {
    vis[j] = stk[j] = true;
    F0R(x,26) {
        if (!adj[i][j][x]) {continue;}
        if (!vis[x]) {dfs(i,x);}
        else if (stk[x]) {flag = true;}
    } stk[j] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("first.in","r",stdin);
    freopen("first.out","w",stdout);

    int n; cin >> n;
    v<string> s(n);
    F0R(i,n) 
        cin >> s[i]; s[i] += "{";
    }

    v<bool> ok(n,true);
    queue<pair<v<int>,int>> q;
    v<int> t(n); iota(all(t),0);
    q.push({t,0});

    while (q.size()) { // dfs into the trie (implicitly stored)
        auto cur = q.front(); q.pop(); // stores current set of indices and depth in trie
        v<int> nxt[27];
        for (int x : cur.f) { // go to all of the children of this node
            nxt[s[x][cur.s]-'a'].pb(x);
        }
        if (nxt[26].size()) { // if some string ends here, that means it's a prefix of all other strings
            F0R(i,26) {for (int j : nxt[i]) {ok[j] = false;}}
        } else {
            F0R(i,26) {
                if (nxt[i].empty()) {continue;}
                for (int x : nxt[i]) { // otherwise draw edges from each index to all other letters
                    F0R(j,26) {
                        if (j!=i && nxt[j].size()) {
                            adj[x][j][s[x][cur.s]-'a'] = true;
                        }
                    }
                }
                q.push({nxt[i],cur.s+1});
            }
        }
    }
    int cnt = 0;
    F0R(i,n) {
        F0R(j,26) {vis[j] = stk[j] = false;}
        flag = false;
        F0R(j,26) { // check for acyclicity (dag)
            if (!vis[j]) {dfs(i,j);}
        }
        if (flag) {ok[i] = false;}
        if (ok[i]) {cnt++;}
    }
    cout << cnt << '\n';
    F0R(i,n) {if (ok[i]) {cout << s[i].substr(0,s[i].size()-1) << '\n';}}
}