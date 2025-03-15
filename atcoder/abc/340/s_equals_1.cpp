#include <bits/stdc++.h>
using namespace std;

#define ll long long

void gcd(ll a, ll b, ll& x, ll& y) {
    if (b==0) {
        x = 1; y = 0;
        return;
    }
    ll x1, y1;
    gcd(b,a%b,x1,y1);
    x = y1;
    y = x1-y1*(a/b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll a, b; cin >> a >> b;

    ll a1 = abs(a), b1 = abs(b);
    ll g = gcd(a1,b1);
    if (g>2) {cout << "-1\n"; return 0;}

    ll x, y;
    gcd(a1,b1,x,y);
    if (g==1) {x *= 2; y *= 2;}
    if (a<0) {x = -x;}
    if (b>0) {y = -y;}
    cout << y << ' ' << x << '\n';
}