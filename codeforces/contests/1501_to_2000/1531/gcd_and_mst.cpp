#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(),x.end()
#define vec vector

void solve() {
    int n; ll p; cin >> n >> p;
    vec<ll> a(n), srt(n);
    vec<bool> used(n);
    for (int i=0;i<n;i++) {cin >> a[i];}
    iota(all(srt),0);
    sort(all(srt),[&](int x, int y) {return a[x]<a[y];});

    int ed = 0;
    ll ans = 0;
    for (int i : srt) {
        if (a[i]>p) {break;}

        int l = i, r = i; // unite all nodes in segment together
        for (;l>=0 && !used[l] && a[l]>=a[i] && (a[l]%a[i]==0);l--) {}
        for (;r<n && !used[r] && a[r]>=a[i] && (a[r]%a[i]==0);r++) {}
        for (int j=l+1;j<r;j++) {used[j] = true;}
        ans += (r-l-2)*a[i]; ed += r-l-2;

        if (l>=0 && a[l]>=a[i] && (a[l]%a[i]==0)) {ans += a[i]; ed++;} // can connect to a previous segment on left
        if (r<n && a[r]>=a[i] && (a[r]%a[i]==0)) {ans += a[i]; ed++;} // can connect to a previous segment on right
    } ans += (n-1-ed)*p;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}