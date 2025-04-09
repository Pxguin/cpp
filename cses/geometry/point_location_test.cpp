#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        ll x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll cross = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1); // cross product
        cout << (cross==0 ? "TOUCH" : (cross<0 ? "RIGHT" : "LEFT")) << '\n';
    }
}
