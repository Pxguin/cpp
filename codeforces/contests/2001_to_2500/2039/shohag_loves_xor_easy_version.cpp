#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

void solve() {
    int x; ll m; cin >> x >> m;
    ll mx = 1<<((int)log2(x)+1), ans = 0; // y cannot have an msb higher than that of x
    FOR(y,1,min(mx,m+1)) { // fix y
        if (y==x) {continue;}
        ans += ((y%(x^y)==0) || (x%(x^y)==0)); // test is it divisor
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}