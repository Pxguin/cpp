#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector

void solve() {
    int n, k; cin >> n >> k;

    vec<ll> a(n), b(n), delta(n,0);
    for (int i=0;i<n;i++) {
        cin >> a[i];
        b[i] = a[i]&-a[i];
    }

    ll mx = b[0];
    for (int i=0;i<n;i++) {
        if (i!=n-1) {
            ll lef = b[i];
            if (a[i]>a[i+1] && a[i]%a[i+1]==0) {
                ll d = a[i]/a[i+1];
                if ((d&-d) == d) {
                    lef = b[i]-2*b[i+1]+1;
                }
            }
            delta[i+1] += lef-b[i];
        }
        if (i) {
            ll rig = b[i];
            if (a[i]>a[i-1] && a[i]%a[i-1]==0) {
                ll d = a[i]/a[i-1];
                if ((d&-d) == d) {
                    rig = b[i]-2*b[i-1]+1;
                }
            }
            mx += rig;
            delta[i] += b[i]-rig;
        }
    }
    bool ans = false;
    for (int i=0;i<n;i++) {
        mx += delta[i];
        if (k>=n && mx>=k) {ans = true;}
    }
    cout << (ans ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}