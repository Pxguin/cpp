#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;
    v<ll> ps(n+1,0);
    F0R(i,n) { // prefix sum
        int a; cin >> a;
        ps[i+1] = ps[i]+a;
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << ps[r]-ps[l] << '\n';
    }
}