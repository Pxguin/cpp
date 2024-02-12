#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int x; long y;
};

vector<vector<Edge>> graph;
queue<int> visit;
int ans;
vector<pair<int,int>> edges;
int nodes; int node;
vector<bool> visited;

int bfs(long k) {
    while (!visit.empty()) {
        node = visit.front(); visit.pop();
        visited[node] = true;
        nodes++;

        for (Edge video: graph[node]) {
            if ((!visited[video.x]) && (video.y >= k)) {visit.push(video.x);}
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mootube.in","r",stdin);freopen("mootube.out","w",stdout);
    int n, q; cin >> n >> q;
    int p_val, q_val, v; long r, k;
    graph.resize(n);
    for (int i=0;i<n-1;i++) {
        cin >> p_val >> q_val >> r; p_val--; q_val--;
        graph[p_val].push_back({q_val, r});
        graph[q_val].push_back({p_val, r});
    }
    for (int i=0;i<q;i++) {
        visited.assign(n,false);
        cin >> k >> v; v--;
        nodes = 0;
        visit.push(v);
        bfs(k);
        cout << nodes-1 << "\n";
    }
}