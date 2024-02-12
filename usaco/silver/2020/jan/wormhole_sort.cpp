#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("wormsort.in", "r", stdin); freopen("wormsort.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int temp, a, b;
    long w;
    vector<pair<int, int>> change;
    vector<pair<int, long>> graph[n];
    long low = 1, high = 1, mid;
    long last_success = -1;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        temp--;
        if (temp != i) { change.push_back({i, temp}); } // pos goal (i) and current pos
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        a--;
        b--;
        high = max(w, high);
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    if (!change.empty()) {
        // binary search
        while (low <= high) {
            mid = (low + high) / 2;

            bool visited[n];
            fill(visited, visited + n, false);
            stack<int> visit;
            int components[n];
            int component = 0; // component number
            bool res = true;
            long node;

            // dfs
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    visit.push(i);
                    while (!visit.empty()) {
                        node = visit.top();
                        visit.pop();
                        visited[node] = true;
                        components[node] = component;
                        for (pair<int, long> edge: graph[node]) { // edge.first = node connected by edge, edge.second = edge width
                            if ((!visited[edge.first]) && (edge.second >= mid)) { visit.push(edge.first); }
                        }
                    }
                    component++;
                }
            }
            for (pair<int, int> i: change) {
                if (components[i.first] != components[i.second]) {res = false; break;}
            }
            if (res) {
                last_success = mid;
                low = mid + 1;
            } else { high = mid - 1; }
        }
    }
    cout << last_success;
}