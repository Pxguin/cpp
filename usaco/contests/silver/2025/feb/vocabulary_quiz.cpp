#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6+1;
int par[MAX_N], dep[MAX_N], outdeg[MAX_N] = {0}, ans[MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    memset(dep,-1,sizeof(dep));
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        int p; cin >> p;
        par[i+1] = p;
        outdeg[p]++;
    } dep[0] = 0;

    outdeg[0]++;
    int m = 0;
    
    for (int i=0;i<n;i++) {
        dep[i+1] = dep[par[i+1]]+1;
        m += (outdeg[i+1]==0);
    }
    while (m--) {
        int a; cin >> a;
        int ans = 0;
        if (outdeg[a]==0) {
            int j = a;
            do {
                ans = dep[j];
                j = par[j];
                outdeg[j]--;
            } while (outdeg[j]+1==1);
        }
        if (outdeg[0]==1) {ans = 0;}
        cout << ans << '\n';
    }
}