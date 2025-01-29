#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    freopen("greedy.in","r",stdin);
    freopen("greedy.out","w",stdout);

    int n; cin >> n;
    v<int> c(n);
    F0R(i,n) {cin >> c[i];}

    int l=1, h=n, m=(l+h)/2, ans;
    while (l <= h) {
        int c2 = n-m; // c2 is length of suffix
        v<int> f(n,0); // frequency array
        F0R(i,m) {f[c[i]]++;}
        int ok = 0;
        F0R(i,n) { // do the greedy simulation
            if (!f[i]) {continue;}
            if (i>=c2) {ok = 1;}
            c2 += f[i];
        }
        if (ok) {h = m-1; ans = n-m;} // find longest possible suffix (smallest m that works)
        else {l = m+1;}
        m = (l+h)/2;
    } cout << ans << '\n';
}