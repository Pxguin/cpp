#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll ans = 0;
    while ((c>a || d>b) && (min(c,d)>0)) { // reduce while c>a, d>b, min(c,d)>0
        if (c>d && c!=a) { // reduce c if c!=a, c>d
            if ((c-a)%d==0) {ans += (c-a)/d; c = a;}
            else {ans += c/d; c %= d;}
        } else if (d>c && d!=b) { // reduce d if d!=b, d>c
            if ((d-b)%c==0) {ans += (d-b)/c; d = b;}
            else {ans += d/c; d %= c;}
        } else {break;} // else, stop
    }
    cout << (c==a && d==b ? ans : -1) << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {solve();}
}