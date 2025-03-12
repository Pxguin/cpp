#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int q; cin >> q;
    const int n = 500000;
    int a[n+1] = {0};
    const int rt = 708;
    int query[rt][rt] = {0}; // query precalc

    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t==1) {
            for (int i=1;i<rt;i++) {
                query[i][x%i] += y; // update query precalc for x<sqrt(n)
            }
            a[x] += y;

        } else {
            int ans = 0;
            if (x>=rt) { // brute force for x>=sqrt(n)
                for (int i=0;i+y<=n;i+=x) {
                    ans += a[i+y];
                }
            } else {ans = query[x][y];} // get precalculated queryh
            cout << ans << '\n';
        }
    }
}