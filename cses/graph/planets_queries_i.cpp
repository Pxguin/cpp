#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

const int MAX_N = 2e5, log2dist = 30;
int succ[MAX_N][log2dist];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;

    F0R(i,n) { // initialize succ array
        cin >> succ[i][0];
        succ[i][0]--;
    }

    FOR(p,1,log2dist) { // update array
        F0R(i,n) {
            succ[i][p] = succ[succ[i][p-1]][p-1];
        }
    }
    while (q--) { // answer queries
        int x, k; cin >> x >> k;
        x--;
        F0R(i,log2dist) {
            if ((1<<i)&k) {x = succ[x][i];}
        } cout << x+1 << '\n';
    }
}