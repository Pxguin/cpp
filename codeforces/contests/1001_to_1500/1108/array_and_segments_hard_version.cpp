#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    v<int> a(n), l(m), r(m);
    v<v<int>> l2(n), r2(n);
    for (int i=0;i<n;i++) {cin >> a[i];}
    for (int i=0;i<m;i++) {
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;

        r2[r[i]].pb(i);
        l2[l[i]].pb(i);
    }

    v<int> mn_l(n,1e7), mn_r(n,1e7);
    v<int> left = a, right = a;
    for (int i=1;i<n;i++) { // find minimum element on left and right of these element
        mn_l[i] = min(mn_l[i-1],a[i-1]);
        for (int s : r2[i-1]) {
            for (int j=l[s];j<=r[s];j++) { // process all new segments on left that don't intersect this element
                left[j]--;
                mn_l[i] = min(mn_l[i],left[j]); // update mni
            }
        }
        int i2 = n-i-1;
        mn_r[i2] = min(mn_r[i2+1],a[i2+1]); // repeat for right side
        for (int s : l2[i2+1]) {
            for (int j=l[s];j<=r[s];j++) {
                right[j]--;
                mn_r[i2] = min(mn_r[i2],right[j]);
            }
        }
    }
    int d = 0, idx = 0;
    for (int i=0;i<n;i++) { // fix each element as max
        if (a[i]-min(mn_l[i],mn_r[i])>d) { // find min by combining answers for left and right
            d = a[i]-min(mn_l[i],mn_r[i]);
            idx = i;
        }
    }

    cout << d << '\n';
    v<int> s;
    for (int i=0;i<m;i++) { // restore answer
        if (l[i]>idx || r[i]<idx) {
            s.pb(i+1);
        }
    }
    cout << s.size() << '\n';
    for (int i : s) {cout << i << ' ';}
}