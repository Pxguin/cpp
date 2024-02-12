#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q; cin >> n;
    vector<int> a(n);
    vector<int> srt(n);
    int m;
    ll t = 0; ll ans;
    ll ps[n+2]; ps[0] = 0; ps[n+1] = 0;
    for (int i=1;i<n+1;i++) {
        cin >> m;
        a[i-1] = m;
        srt[i-1] = m; // sorted
    }
    sort(srt.begin(), srt.end());
    for (int i=1;i<n+1;i++) {
        ps[i] = ps[i-1]+srt[i-1];
        t += (ll)i*srt[i-1];
    }

    int i, j;
    cin >> q;

    while (q--) {
        cin >> i >> j;
        ans = t;
        ll it = lower_bound(srt.begin(), srt.end(), a[i-1])-srt.begin()+1;
        ll it2 = lower_bound(srt.begin(), srt.end(), j)-srt.begin()+1;
        it2 -= (j > a[i-1]);

        ans -= a[i-1]*it;
        ans += it2*j;

        if (it2 > it) {ans -= ps[it2]-ps[it];}
        else {ans += ps[it-1]-ps[it2-1];}

        cout << ans << "\n";
    }
}