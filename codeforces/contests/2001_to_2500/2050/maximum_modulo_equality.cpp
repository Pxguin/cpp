#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

void solve() {
    int n, q; cin >> n >> q;
    vec<int> a(n), diff(n), blocks(n,0);
    F0R(i,n) {cin >> a[i];}
    const int B = ceil(sqrt(n));
    
    F0R(i,n-1) {
        diff[i] = abs(a[i+1]-a[i]);
        blocks[i/B] = gcd(blocks[i/B],diff[i]);
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int ret = 0;

        if (r-l<B) { // side case
            FOR(i,l,r) {ret = gcd(ret,diff[i]);}
        } else { // find gcd on the segment [l,r]
            FOR(i,l/B+1,r/B) {ret = gcd(ret,blocks[i]);}
            FOR(i,l,(l/B+1)*B) {ret = gcd(ret,diff[i]);}
            FOR(i,r/B*B,r) {ret = gcd(ret,diff[i]);}
        }
        cout << ret << ' ';
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}    
}