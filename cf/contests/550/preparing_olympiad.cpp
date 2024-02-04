#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
int n, l, r, x; vector<int> c;
int ans = 0;
 
void solve() {
    for (int mask=0;mask<(1<<n);mask++) {
        long long cur = 0; int p = 0;
        int mx = INT_MIN; int mn = INT_MAX;
        for (int i=0;i<n;i++) {
            if (mask&(1<<i)) {
                cur += c[i]; 
                p++;
                mx = max(mx, c[i]);
                mn = min(mn, c[i]);
            }
        }
        // check for at least two problems
        if (p >= 2 && cur >= l && cur <= r && mx-mn>=x) {ans++;}
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> l >> r >> x;
    c.resize(n);
    for (int i=0;i<n;i++) {cin >> c[i];}
    solve();
}