#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

vector<vector<int>> graph;
vector<bool> vis;
vector<int> pots;
vector<int> sums;
int ans = 0;

int calc(int cur) {
    vis[cur] = true;
    int sum = 0;
    for (int child : graph[cur]) {
        if (!vis[child]) {sum += calc(child);}
    }
    if (graph[cur].size() == 1 && cur != 0) {sum = 1;}
    sums[cur] = sum;
    return sum;
}

int dfs(int cur) {
    vis[cur] = true;
    for (int child : graph[cur]) {
        if (!vis[child]) {pots[cur] += dfs(child);}
    }
    ans -= max(0,pots[cur]-sums[cur]);
    return min(sums[cur],pots[cur]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    graph.resize(n);
    vis.resize(n, false);
    pots.resize(n, 0);
    sums.resize(n, 0);

    int p[n];
    int a, b;
    for (int i=0;i<n;i++) {cin >> p[i]; p[i]--;}

    for (int i=0;i<n-1;i++) {
        cin >> a >> b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    calc(0);
    ans = sums[0];
    fill(vis.begin(), vis.end(), false);
    for (int i=0;i<ans;i++) {pots[p[i]]++;}

    dfs(0);
    cout << ans << "\n";
}