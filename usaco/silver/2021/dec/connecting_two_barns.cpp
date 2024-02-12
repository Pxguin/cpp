#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int cn;

void dfs(int node, const vector<vector<int>>& graph, vector<int>& comps) {
    comps[node] = cn;
    for (int i : graph[node]) {
        if (comps[i] == -1) {dfs(i, graph, comps);}
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int m; cin >> n >> m;
        int a, b;
        vector<vector<int>> graph(n);
        vector<int> comps(n,-1);
        vector<long> first; vector<long> last; vector<long> middle;
        cn = 0;
        for (int i=0;i<m;i++) {
            cin >> a >> b; a--; b--;
            graph[a].push_back(b); graph[b].push_back(a);
        }

        for (int i=0;i<n;i++) {
            if (comps[i] == -1) {dfs(i, graph, comps); cn++;}
        }
        for (int i=0;i<n;i++) {
            if (comps[i] == 0) {
                first.push_back(i);
            } else  {
                if (comps[i] == comps[n-1]) {
                    last.push_back(i);
                } middle.push_back(i);
            }
        }
        first.push_back(LONG_MAX);
        last.push_back(LONG_MAX);
        long long ans = LLONG_MAX;
        if (comps[0] == comps[n-1]) {ans = 0;}
        else {
            vector<long long> dist1(cn, LLONG_MAX);
            vector<long long> dist2(cn, LLONG_MAX);

            unsigned long p1 = 0;
            unsigned long p2 = 0;
            for (long i : middle) {
                while ((abs(i-first[p1])) > abs(i-first[p1+1])) {p1++;}
                dist1[comps[i]] = min(dist1[comps[i]], (long long)abs(i-first[p1]));

                while ((abs(i-last[p2])) > abs(i-last[p2+1])) {p2++;}
                dist2[comps[i]] = min(dist2[comps[i]], (long long)abs(i-last[p2]));
            }

            for (int i=1;i<cn;i++) {
                ans = min(ans, dist1[i] * dist1[i] + dist2[i] * dist2[i]);
            }
        }
        cout << ans << "\n";
    }
}