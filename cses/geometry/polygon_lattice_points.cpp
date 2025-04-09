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
    ll a = 0, b = 0;
    for (int i=0;i<n;i++) {
        int j = (i+1)%n;
        a += x[i]*y[j]-y[i]*x[j]; // 2 * area of polygon
        b += gcd(abs(x[j]-x[i]),abs(y[j]-y[i])); // points on boundary
    }
    a = abs(a);

    ll in = (a+2-b)/2; // interior points
    cout << in << ' ' << b << '\n';
}
