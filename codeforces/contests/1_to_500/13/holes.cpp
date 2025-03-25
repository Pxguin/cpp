#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5, K = 316;
int to[MAX_N], last[MAX_N], a[MAX_N], num[MAX_N];
int n;

void recalc(int i) { // recalculate dp value (the first reachable index from i in a block after i)
    if (i+a[i]>=n || (i+a[i])/K!=i/K) {
        to[i] = i+a[i]; // dp value
        last[i] = i; // last thing it jumps out of
        num[i] = 1; // number of jumps
    } else {
        to[i] = to[i+a[i]];
        last[i] = last[i+a[i]];
        num[i] = 1+num[i+a[i]];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int m; cin >> n >> m;
    for (int i=0;i<n;i++) {cin >> a[i];}
    for (int i=n-1;i>=0;i--) {
        recalc(i);
    }
    while (m--) {
        int t; cin >> t;
        if (!t) { // update this block
            int x, b; cin >> x >> b; x--;
            a[x] = b;
            int lb = x/K*K;
            for (int i=x;i>=lb;i--) {recalc(i);}
        } else {
            int x; cin >> x; x--;
            int ans = x, ans2 = 0;
            while (x<n) { // simulate
                ans = last[x];
                ans2 += num[x];
                x = to[x];
            }
            cout << ans+1 << ' ' << ans2 << '\n';
        }
    }

}