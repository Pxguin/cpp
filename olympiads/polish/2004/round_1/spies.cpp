#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int to[N], indeg[N] = {0};
bitset<N> marked;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    int ans = 0;
    for (int i=0;i<n;i++) {
        cin >> to[i]; --to[i];
        indeg[to[i]]++;
    }

    queue<int> q;
    for (int i=0;i<n;i++) {
        if (indeg[i]==0) {q.push(i);}
    }
    auto run = [&]() {
        while (q.size()) {
            int cur = q.front(); q.pop();
            if (!marked[cur] && !marked[to[cur]]) {
                marked.set(cur); marked.set(to[cur]);
                ans++;
            }
            if (--indeg[to[cur]]==0) {q.push(to[cur]);}
        }
    };
    run();
    for (int i=0;i<n;i++) {
        if (indeg[i]) {
            indeg[i] = 0; q.push(i);
            run();
        }
    } cout << ans << '\n';
}