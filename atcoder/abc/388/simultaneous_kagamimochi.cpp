#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

int a[500001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    F0R(i,n) {
        cin >> a[i];
    }

    int l = 0, h = n/2, m = (l+h)/2, ans = 0;
    while (l <= h) { // binary search on K
        int ok = 1;
        for (int i=m-1;i>=0;i--) { // pair up bottom K mochi with top K mochi
            ok &= (a[i]*2 <= a[n-(m-i)]);
        }
        if (ok) {l = m+1; ans = m;} // if we can pair all of them up, then the mid works
        else {h = m-1;}
        m = (l+h)/2;
    } cout << ans << '\n';
}