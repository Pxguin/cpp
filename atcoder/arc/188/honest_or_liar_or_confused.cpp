#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmax(a, b) a = max(a,b)
#define vec vector

const int N = 2e5;
vec<int> radj[N];
vec<int> adj[N][2];
int col[N], ans[N];
bool vis[N] = {false};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0;i<m;i++) {
        int a, b, c; cin >> a >> b >> c;
        radj[--b].pb(--a);
        adj[a][c].pb(b);
    }
    memset(col,-1,sizeof(col));
    for (int i=0;i<n;i++) {
        if (!vis[i]) {
            queue<int> q; q.push(i);
            while (q.size()) {
                int cur = q.front(); q.pop();
                vis[cur] = true;
                int col1[2] = {-1,-1};
                for (int j=0;j<2;j++) { // check if any adjacent vertices have existing colors
                    for (int x : adj[cur][j]) {
                        chmax(col1[j],col[x]);
                    }
                }
                if (col1[0]==-1 && col1[1]==-1) {col1[0] = 0; col1[1] = 1;} // col1[0]: what will we color outgoing nodes of type 1 edges
                else if (col1[0]==-1 && col1[1]!=-1) {col1[0] = !col1[1];} // col1[1]: what will we color outgoing nodes of type 2 edges
                else if (col1[1]==-1 && col1[0]!=-1) {col1[1] = !col1[0];}

                for (int j=0;j<2;j++) {
                    for (int x : adj[cur][j]) { // assign colors to vertices (such that edges of same type point to vertices of same type)
                        if (col[x]!=-1) {continue;}
                        col[x] = col1[j];
                        for (int y : radj[x]) { // we can now process all vertices pointing to x
                            if (!vis[y]) {
                                q.push(y);
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i=0;i<n;i++) { // all nodes are colored, except for those with indegree 0
        int color = 0;
        if (adj[i][0].size()) {color = col[adj[i][0][0]];} // determine what the color of this vertex should be via color of adjacent nodes
        else if (adj[i][1].size()) {color = !col[adj[i][1][0]];}
        for (int x : adj[i][0]) {
            if (col[x]!=color) {color = -1;}
        }
        for (int x : adj[i][1]) {
            if (col[x]==color) {color = -1;}
        }
        if (color==-1) {ans[0] = -1;} // if this villager cannot be colored without creating contradictions, there's no answer 
        else {ans[i] = (color!=col[i]);} // this villager is confused if the color does not match the preassigned color
    }
    if (ans[0]==-1) {cout << -1;}
    else {
        for (int i=0;i<n;i++) {cout << ans[i];}
    }
}