#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int ans = 0;
vector<int> farms[100001];
bool visited[100001];

void dfs(int node) {
    visited[node] = true;
    
    int available = 0;
    for (int adj : farms[node]) {
        if (!visited[adj]) {available++; dfs(adj);}
    }
    if (available > 0) {ans += log2(available)*2/2+1 + available;}
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int a, b;
    visited[0] = true;
    for (int i=0;i<n-1;i++) {
        cin >> a >> b;
        farms[a].push_back(b); farms[b].push_back(a);
        visited[i+2] = false;
    }
    dfs(1);
    cout << ans;
}