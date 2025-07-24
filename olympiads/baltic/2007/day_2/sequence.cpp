#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);

    int n; cin >> n;
    ll ans = 0;
    vec<int> a(n);
    for (int i=0;i<n;i++) {cin >> a[i];}
    for (int i=0;i<n;i++) {
        if (i && a[i]>=a[i-1]) {ans += a[i];} // left range
        if (i!=n-1 && a[i]>a[i+1]) {ans += a[i];} // right range
    } cout << ans << '\n';
}