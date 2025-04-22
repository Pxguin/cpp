#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmax(a, b) a = max(a,b)
#define vec vector

void solve() {
    int n; cin >> n;
    vec<int> a(n);
    ll l = 0, r = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if (i && a[i]<0) {r += -a[i];} // initial suffix sum
    }
    ll ans = l+r+abs(a[0]);
    for (int i=0;i<n-1;i++) {
        if (a[i+1]<0) {r += a[i+1];} // suffix: all negatives
        if (a[i]>0) {l += a[i];} // prefix: all positives
        chmax(ans,l+r+abs(a[i+1])); // try all
    } cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {solve();}
}