#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int r, b, k; cin >> r >> b >> k;
    if (r>b) {swap(r,b);}

    int g = gcd(r,b);
    return ((b-g-1)/r+1<k);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {cout << (solve() ? "OBEY" : "REBEL") << '\n';}
}