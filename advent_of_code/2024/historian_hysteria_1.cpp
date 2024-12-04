#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<int> a(n), b(n);
    F0R(i,n) {cin >> a[i] >> b[i];}
    sort(all(a)); sort(all(b));

    ll ans = 0;
    F0R(i,n) {ans += abs(a[i]-b[i]);}
    cout << ans << '\n';
}