#include <iostream>
#include <vector>
using namespace std;

int cows[100000];
bool visited[100000];
bool cycle[100000];
vector<int> cycle1;
bool cycled;
int ans = 0;

void dfs(int node) {
    visited[node] = true;
    cycle1.push_back(node);

    if (visited[cows[node]]) { // if this node is visited and is not already marked as part of a cycle, then there is a cycle
        if (!cycle[cows[node]]) {
            cycled = true;
            for (int i=0;i<cycle1.size();i++) {
                if (cycle1[i] == cows[node]) {
                    for (int j=i;j<cycle1.size();j++) {
                        cycle[cycle1[j]] = true;
                        ans++;
                    }
                    break;
                }
            }
        }
    } else {dfs(cows[node]);}
}



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("shuffle.in","r",stdin); freopen("shuffle.out","w",stdout);
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        cin >> cows[i]; cows[i]--; 
        visited[i] = false;
        cycle[i] = false;
    }
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            cycle1.clear();
            dfs(i);
        }
    }
    cout << ans;
}