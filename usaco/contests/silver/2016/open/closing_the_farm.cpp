#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<bool> closed;
vector<vector<int>> graph;
vector<bool> vis;
int comp = 0;

void dfs(int cur) {
    vis[cur] = true;
    comp++;
    for (int i : graph[cur]) {
        if (!closed[i] && !vis[i]) {dfs(i);}
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);

    int n, m; cin >> n >> m;
    closed.resize(n, false); graph.resize(n);
    vis.resize(n);
    unordered_set<int> barns;
    int a, b;
    for (int i=0;i<m;i++) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    for (int i=0;i<n;i++) {barns.insert(i);}

    for (int i=0;i<n;i++) {
        comp = 0;
        fill(vis.begin(), vis.end(), false);

        dfs(*barns.begin());
        if (comp == n-i) {cout << "YES\n";}
        else {cout << "NO\n";}

        cin >> a; a--;
        barns.erase(a);
        closed[a] = true;
    }

}