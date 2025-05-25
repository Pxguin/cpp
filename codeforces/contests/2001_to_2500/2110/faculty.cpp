#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define vec vector

void solve() {
    int n; cin >> n;
    vec<int> a(n);
    int mx = 0, mx2 = 0, ans = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        
        if (a[i]>mx) { // update max
            mx2 = mx; mx = a[i];
            if (mx2<=mx/2) { // recalculate answer if nothing is <mx, >mx/2
                for (int j=0;j<=i;j++) {chmax(ans,a[j]%mx + mx%a[j]);}
            }
        } else if (a[i]<mx && a[i]>mx2) { // change mx2
            mx2 = a[i];
        }
        if (a[i]<=mx/2) { // if not >mx/2, update answer
            chmax(ans,a[i]%mx + mx%a[i]);
        }
        if (mx2>mx/2) {ans = mx;} // if something is >mx/2, answer is mx

        cout << ans << ' ';
        
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}