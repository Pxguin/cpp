#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;
    vec<ll> a(n), d(n), val(n), ps(n), ss(n);
    for (int i=0;i<n;i++) {cin >> a[i];}
    for (int i=0;i<n;i++) {cin >> d[i];}

    ll ans = 0, tot = 0;
    for (int i=n-1;i>=0;i--) {
        val[i] = (tot+=a[i])-d[i];
    }
    ps[0] = val[0];
    for (int i=1;i<n;i++) {
        ps[i] = max(val[i],ps[i-1]);
    }
    ss[n-1] = val[n-1];
    for (int i=n-2;i>=0;i--) {
        ss[i] = max(val[i],ss[i+1]);
    }

    
    if (k==0) {
        chmax(ans,ss[0]); // can't do anything
    } else if (k>=2) {
        chmax(ans,tot-*min_element(d.begin(),prev(d.end()))); // path from i to N
        chmax(ans,ss[0]); // excite N by itself
    } else {
        for (int i=0;i<n-2;i++) { // connect to i+2
            chmax(ans,ps[i]-a[i+1]);
            chmax(ans,ps[i]-d[i+1]);
        }

        tot = 0;
        ll mn = INT_MAX;
        for (int i=0;i<n-1;i++) { // connect to 1
            chmin(mn,d[i]);
            tot += a[i];

            chmax(ans,ss[i+1]);
            chmax(ans,tot-mn);
            chmax(ans,tot-mn+ss[i+1]);
        }
    }
    cout << ans << '\n';
}