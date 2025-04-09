#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vec<ll> x(n), y(n);
    for (int i=0;i<n;i++) {
        cin >> x[i] >> y[i];
    }
    ll ans = 0;
    for (int i=0;i<n;i++) {
        int j = (i+1)%n;
        ans += x[i]*y[j]-y[i]*x[j]; // shoelace theorem
    } cout << abs(ans) << '\n';
}
