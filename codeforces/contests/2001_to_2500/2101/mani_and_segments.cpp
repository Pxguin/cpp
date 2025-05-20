#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmax(a, b) a = max(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

void solve() {
    int n; cin >> n;
    vec<int> a(n);
    for (int i=0;i<n;i++) {cin >> a[i];}
    vec<vec<int>> bound(2,vec<int>(n));

    auto fillin = [&](int m) { // calculate dp values on left/right
        vec<int> hi(n), lo(n);
        stack<int> sh, sl; // nearest smaller/larger values
        for (int i=0;i<n;i++) {
            while (sh.size()&&a[i]>a[sh.top()]) {sh.pop();}
            while (sl.size()&&a[i]<a[sl.top()]) {sl.pop();}
            hi[i] = (sh.empty() ? -1 : sh.top());
            lo[i] = (sl.empty() ? -1 : sl.top());
            sh.push(i); sl.push(i);
        }
        bound[m][0] = 0;
        for (int i=1;i<n;i++) {
            bound[m][i] = bound[m][i-1]; // base case
            if (a[i]>a[i-1] && hi[i]<hi[i-1]) {chmax(bound[m][i],hi[i-1]+1);} // if a[i]>a[i-1], then LDS changes
            if (a[i]<a[i-1] && lo[i]<lo[i-1]) {chmax(bound[m][i],lo[i-1]+1);} // if a[i]<a[i-1], then LIS changes
        }
        if (m==1) { // if m=1 (calculating for right), then need to re-reverse all values to right side
            vec<int> b2 = bound[1];
            for (int i=0;i<n;i++) {bound[m][i] = n-b2[n-i-1]-1;}
        }
        reverse(all(a)); // reverse array, to transform calculating dp values on right to calc on left
    };
    fillin(0); fillin(1);

    int last_r = bound[1][0];
    ll ans = last_r+1;
    for (int i=1;i<n;i++) { // union of answers
        ans += (bound[1][i]-i+1);
        ans += (ll)(bound[1][i]-last_r)*(i-bound[0][i]);
        last_r = bound[1][i];
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}