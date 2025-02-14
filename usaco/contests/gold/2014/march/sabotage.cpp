#include <bits/stdc++.h>
using namespace std;

#define ld long double

const int MAX_N = 1e5;
int n;
ld a[MAX_N], tot = 0;

bool check(ld x) {
    ld mx = a[1]-x, cur = mx;
    for (int i=1;i<n-1;i++) { // max subarray sum
        if (cur<0) {cur = 0;}
        cur += a[i]-x;
        mx = max(mx,cur);
    }
    return (tot-mx)<=x*n; // does it work
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("sabotage.in","r",stdin);
    freopen("sabotage.out","w",stdout);

    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        tot += a[i];
    }

    ld l = 0, h = 10000, m = (l+h)/2, ans = 10000;
    int t = 100;
    
    for (int i=0;i<t;i++) { // binary search on average
        if (check(m)) {
            ans = m;
            h = m;
        } else {l = m;}
        m = (l+h)/2;
    } cout << fixed << setprecision(3) << ans << '\n';
}