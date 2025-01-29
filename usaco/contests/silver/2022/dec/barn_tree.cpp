#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
vector<long long> sums;
vector<vector<long>> ans;
vector<int> connect;

long long avg = 0;
long orders = 0;

int n;

void dfs(int node, int parent) { // moves all the excess bales in each subtree
    visited[node] = true;
    for (int i:tree[node]) {
        if (!visited[i]) {dfs(i, node);}
    }
    sums[parent] += sums[node];
    connect[parent] += connect[node];
    if (sums[node] > avg*connect[node] && parent != n) {
        long transfer = sums[node]-(long)avg*connect[node];
        ans.push_back({node+1,parent+1,transfer}); orders++;
        sums[node]-transfer;
    }
}

void dfs2(int node, int parent) { // fills subtrees with missing bales
    visited[node] = true;
    if (sums[node] < avg*connect[node]) {
        long transfer = (avg*connect[node])-sums[node];
        ans.push_back({parent+1,node+1,transfer}); orders++;
        sums[node] = avg*connect[node];
    }
    for (int i:tree[node]) {
        if (!visited[i]) {dfs2(i,node);}
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; int u; int v; long h;
    sums.resize(n); connect.resize(n+1);
    for (int i=0;i<n;i++) {
        cin >> h; sums[i]=h;
        avg += h;
    }
    sums.push_back(0);
    avg /= n;
    tree.resize(n);
    for (int i=0;i<n-1;i++) {
        cin >> u >> v; v--; u--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    fill(connect.begin(),connect.end(),1);
    visited.resize(n);
    fill(visited.begin(),visited.end(),false);

    dfs(0, n);
    fill(visited.begin(),visited.end(),false);
    dfs2(0,n);

    cout << orders << "\n";
    cout << ans[0][0] << " " << ans[0][1] << " " << ans[0][2];
    for (int i=1;i<ans.size();i++) {
        cout << "\n" << ans[i][0] << " " << ans[i][1] << " " << ans[i][2];
    }
}
