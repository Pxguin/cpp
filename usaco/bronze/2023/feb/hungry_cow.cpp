#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n, t, d, b; cin >> n >> t;
    ll left = 0, ans = 0, last = 0;
    while (n--) {
        cin >> d >> b;
        ll delta = min(left,d-1-last);
        left -= delta; ans += delta;
        last = d-1;
        left += b;
    }
    ans += min(left,t-last);
    cout << ans << '\n';
}