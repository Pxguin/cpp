#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

const int MAX_N = 2e5+1, l2d = 18;
int a[MAX_N], st[l2d][MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    } a[n] = INT_MAX;

    for (int i=0,j=0;i<n;i++) {
        while (a[i]*2>a[j]) {j++;} // calc b array
        st[0][i] = j-i;
    }
    for (int i=1;i<l2d;i++) { // set up bin lift/sparse table stuff
        for (int j=0;j+(1<<i)-1<n;j++) {
            st[i][j] = max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int lo = 1, hi = (r-l+1)/2, mid = (lo+hi)/2, ans = 0; // binary search on K
        while (lo <= hi) {
            int b = __builtin_clzll(1)-__builtin_clzll(mid);
            int mx = max(st[b][l],st[b][l+mid-(1<<b)]); // range max query
            int res = mid+l+max(mx,mid)-1; // basically get lhs of equation

            if (res<=r) {lo = mid+1; ans = mid;} // compare it to R
            else {hi = mid-1;}
            mid = (lo+hi)/2;
        } cout << ans << '\n';
    }
}