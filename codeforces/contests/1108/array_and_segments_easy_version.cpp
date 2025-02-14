#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    v<int> a(n), l(m), r(m);
    for (int i=0;i<n;i++) {cin >> a[i];}
    for (int i=0;i<m;i++) {
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    }

    int d = 0, idx = 0;
    for (int i=0;i<n;i++) {
        v<int> diff(n+1,0);
        for (int j=0;j<m;j++) { // add all segments that don't cross this index
            if (l[j]>i || r[j]<i) {
                diff[l[j]]--; diff[r[j]+1]++;
            }
        }
        
        int mn = INT_MAX; // use difference array to process all segments
        for (int j=0;j<n;j++) {
            diff[j+1] += diff[j];
            mn = min(mn,diff[j]+a[j]); // find minimum element
        }
        if (a[i]-mn > d) { // update answer
            d = a[i]-mn; idx = i;
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