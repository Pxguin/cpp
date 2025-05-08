#include <bits/stdc++.h>
using namespace std;

#define vec vector

void solve() {
    int n; cin >> n;
    vec<vec<int>> a(n,vec<int>(2));
    vec<int> id(2*n+1,-1);
    for (int i=0;i<n;i++) {cin >> a[i][0];}
    for (int i=0;i<n;i++) {
        cin >> a[i][1];
        id[min(a[i][0],a[i][1])] = i;
    }
    vec<vec<vec<bool>>> dp(n,vec<vec<bool>>(2,vec<bool>(2,false))); // dp[i][j][k]: index i, j=0/1 inverted?, k=0/1 even/odd # of operations
    dp[id[1]][0][0] = dp[id[1]][1][1] = true;
    int last = id[1];
    for (int i=2;i<=2*n;i++) {
        int cur = id[i];
        if (cur==-1) {continue;}
        for (int invlast=0;invlast<2;invlast++) { // fix inversion state of last pair
            for (int parity=0;parity<2;parity++) { // fix even/odd swaps so far
                if (!dp[last][invlast][parity]) {continue;}
                
                for (int invcur=0;invcur<2;invcur++) { // fix inversion state of this pair
                    if (a[cur][invcur]>a[last][invlast] && a[cur][!invcur]>a[last][!invlast]) { // transition
                        dp[cur][invcur][parity^invcur] = true;
                    }
                }
            }
        } last = cur;
    }
    cout << (max(a[last][0],a[last][1])!=2*n ? "NO" : (dp[last][0][0]||dp[last][1][0] ? "YES" : "NO")) << '\n';
    // if last pair contains 2n, and can achieve sort with an even number of vertical swaps
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}
