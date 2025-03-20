#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define pii pair<int,int>
#define mp make_pair

vector<vector<int>> ans(2);
bool cmp(const pii& x, const pii& y) {return ans[x.s][x.f]<=ans[y.s][y.f];}

void solve() {
    int n, m, a, b; cin >> n >> m;
    vector<vector<int>> adj(n), adj2(n);
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    q.push(0); dist[0] = 0;
    for (int i=0;i<m;i++) {
        cin >> a >> b; a--; b--;
        adj[a].pb(b); adj2[b].pb(a);
    }
    while (q.size()) {
        int cur = q.front(); q.pop();
        for (int x : adj[cur]) {
            if (dist[x] == INT_MAX) {
                dist[x] = dist[cur]+1;
                q.push(x);
            }
        }
    }

    ans.clear(); ans.resize(2);
    set<pii, decltype(&cmp)> ok(cmp); 
    for (int i=0;i<n;i++) {ans[0].pb(dist[i]); ans[1].pb(dist[i]);} 
    for (int i=0;i<n;i++) {ok.insert(mp(i,0)); ok.insert(mp(i,1));}

    while (ok.size()) {
        pii cur = *ok.begin(); ok.erase(ok.begin());
        for (int x : adj2[cur.f]) {
            if (cur.s) { // 1 case
                if (dist[x] < dist[cur.f] && ans[1][cur.f] < ans[1][x]) {
                    ans[1][x] = ans[1][cur.f];
                    ok.erase(mp(x,1)); ok.insert(mp(x,1));
                }
            } else { // 0 case
                if (dist[x] < dist[cur.f] && ans[0][cur.f] < ans[0][x]) {
                    ans[0][x] = ans[0][cur.f];
                    ok.erase(mp(x,0)); ok.insert(mp(x,0));
                } else {
                    if (ans[0][cur.f] < ans[1][x]) {
                        ans[1][x] = ans[0][cur.f];
                        ok.erase(mp(x,1)); ok.insert(mp(x,1));
                    }
                }
            }
        }
    }
    for (int i=0;i<n;i++) {
        cout << min(ans[0][i],ans[1][i]) << ' ';
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {solve();}
}