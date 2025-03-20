#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;
 
vector<unordered_set<int>> graph;
set<int> unvis;
int c = 0;
 
void dfs(int cur) {
    c++;
    auto it = unvis.begin();
    while (it != unvis.end()) {
        if (graph[cur].count(*it)) {it++;} 
        else {
            int i = *it;
            unvis.erase(i);
            dfs(i);
            it = unvis.upper_bound(i);
        }
    }
}
 
void solve() {
    int n, m; cin >> n >> m;
    vector<int> ans;
    graph.resize(n);
    
    int x, y;
    for (int i=0;i<m;i++) {
        cin >> x >> y; x--; y--;
        graph[x].insert(y); graph[y].insert(x);
    }
    for (int i=0;i<n;i++) {unvis.insert(i);}
    
    while (!unvis.empty()) {
        int i = *unvis.begin();
        unvis.erase(unvis.begin());
        c = 0;
        dfs(i);
        ans.push_back(c);
    }
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (int i : ans) {cout << i << " ";}
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}