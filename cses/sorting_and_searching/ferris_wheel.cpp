#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, x; cin >> n >> x;
    v<int> p(n);
    F0R(i,n) {cin >> p[i];}
    sort(all(p));

    int p1 = 0, p2 = n-1, ans = 0;
    while (p1<=p2) {
        int cur = p[p2]; // first child
        if (p1<p2 && p[p1]+cur<=x) {cur += p[p1++];} // fit lightest second child
        p2--; ans++;
    } cout << ans << '\n';
}