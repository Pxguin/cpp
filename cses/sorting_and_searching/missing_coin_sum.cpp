#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(),x.end()
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vec<int> x(n);
    for (int i=0;i<n;i++) {cin >> x[i];}
    sort(all(x));

    ll mx = 0;
    for (int i=0;i<n;i++) {
        if (x[i]<=mx+1) {mx += x[i];}
    } cout << mx+1 << '\n';
}