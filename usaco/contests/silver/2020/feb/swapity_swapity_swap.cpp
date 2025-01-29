#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("swap.in","r",stdin);freopen("swap.out","w",stdout);
    int n, m; long k; cin >> n >> m >> k;
    int l, r;
    set<int> visit;
    pair<int,int> swaps[m];
    for (int i=0;i<m;i++) {cin>>l>>r;l--;r--;swaps[i]={l,r};}
    for (int i=0;i<n;i++) {visit.insert(i);}

    int output[n];

    while (!visit.empty()) {
        vector<int> cycle;
        int start = *visit.begin();
        int node = start;
        do {
            visit.erase(node);
            cycle.push_back(node);
            for (pair<int,int> swap: swaps) {
                if (swap.first <= node && node <= swap.second) {
                    node = swap.first+swap.second-node;
                }
            }
        } while (node != start);
        int mod = k % cycle.size();
        for (int i=0;i<cycle.size();i++) {
            output[cycle[(mod+i)%cycle.size()]] = cycle[i]+1;
        }
    }

    for (int i:output) {cout << i << "\n";}
    
}