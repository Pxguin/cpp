#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
 
vector<bool> vis;
vector<unordered_set<int>> graph;
 
bool dfs(int cur, int par) {
    vis[cur] = true;
 
    for (int i : graph[cur]) {
        if (vis[i]) {
            if (i != par) {return true;}
        } else {
            if (dfs(i, cur)) {return true;};
        }
    }
    return false;
}
 
void solve() {
    int n; cin >> n;
    vis.clear(); vis.resize(n, false);
    graph.clear(); graph.resize(n);
 
    int a;
 
    for (int i=0;i<n;i++) {
        cin >> a; a--;
        graph[i].insert(a);
        graph[a].insert(i);
    }
    
    int cycles = 0; int components = 0;
    for (int i=0;i<n;i++) {
        if (!vis[i]) {
            if (dfs(i, *graph[i].begin())) {
                cycles++;
            } else {components++;}
        }
    }
    int ans = cycles+(bool)components;
    cout << ans << " " << components+cycles << "\n";
 
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {solve();}
}
