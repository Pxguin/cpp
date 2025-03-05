#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5, l2d = 20;
int st[l2d][MAX_N]; // st[i][j]: minimum from [j,j+2^i-1]

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;
    for (int i=0;i<n;i++) {cin >> st[0][i];} // base cases for sparse table

    for (int i=1;i<l2d;i++) {
        for (int j=0;j+(1<<i)-1<n;j++) {
            st[i][j] = min(st[i-1][j],st[i-1][j+(1<<(i-1))]); // update sparse table
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;
        r--;

        int i = log2(r-l+1);
        cout << min(st[i][l],st[i][r-(1<<i)+1]) << '\n'; // query sparse table
    }
}