#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define f first
#define s second
#define pb push_back

int n, k;
vector<pair<int,int>> g;
vector<vector<int>> freq;
vector<int> adj;
vector<pair<int,int>> ans;
bool solve() {
    freq[0].pb(g[0].s);
    for (int i=1;i<n;i++) {
        auto& j = g[i];
        auto& p = freq[j.f-1];
        if (p.empty()) {return false;}
        else {
            ans.emplace_back(g[i].s, p.back());
            if (++adj[p.back()] == k) {
                p.pop_back();
            }
            adj[j.s]++;
            if (adj[j.s] < k) {
                freq[j.f].pb(j.s);
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    g.resize(n); freq.resize(n); adj.resize(n, 0);
    int m; int z = 0;
    for (int i=0;i<n;i++) {
        cin >> m;
        g[i] = {m,i};
        if (m == 0) {z++;}
    } sort(g.begin(), g.end());

    if (z == 1 && solve()) {
        cout << ans.size() << "\n";
        for (auto i : ans) {cout << i.f+1 << " " << i.s+1 << "\n";}
    } else {cout << "-1\n";}

}