#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vec<int> a(n);
    for (int i=0;i<n;i++) {cin >> a[i];}

    int ans = 1;
    sort(all(a));
    a.resize(n=(unique(all(a))-a.begin()));
    int g = 0;
    for (int i=1;i<n;i++) { // get gcd
        g = gcd(g,a[i]-a[i-1]);
    }
    if (g<2) { // if gcd>=2, then answer is 1
        int cnt[2] = {0,0}; // else set m=2
        for (int i=0;i<n;i++) {cnt[a[i]%2] = 1;}
        ans = cnt[0]+cnt[1];
    }
    cout << ans << '\n';
}