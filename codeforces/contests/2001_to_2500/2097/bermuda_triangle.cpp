#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

pair<ll,ll> euclid(ll a, ll b) { // extended euclidean algorithm
    if (b==0) {return {1,0};}
    else {
        pair<ll,ll> res = euclid(b,a%b);
        return {res.s,res.f-res.s*(a/b)};
    }
}

void solve() {
    ll n, x, y, a, b; cin >> n >> a >> b >> x >> y;
    
    ll g = gcd(x,y);
    x /= g; y /= g; // reduce velocity vector

    ll x1 = x, y1 = y; // keep defaults for later

    ll a1 = n-a, b1 = n-b; // modular residues for crt
    ll m1 = n, m2 = n; // modulos for crt

    ll g1 = gcd(n,x), g2 = gcd(n,y);
    bool flag = false;
    if (g1!=1) { // reduce mod equations kx = a mod b ,  by gcd(x,b)
        if (a1%g1==0) {a1 /= g1; x /= g1; m1 /= g1;}
        else {flag = true;} // failed
    }
    if (g2!=1) {
        if (b1%g2==0) {b1 /= g2; y /= g2; m2 /= g2;}
        else {flag = true;}
    }

    a1 = (a1*euclid(x,m1).f %m1+m1)%m1; // get rid of x by multiply by mod inverse
    b1 = (b1*euclid(y,m2).f %m2+m2)%m2;

    pair<ll,ll> c = euclid(m1,m2); // bezout coefficients
    g = gcd(m1,m2);
    ll lm = lcm(m1,m2);

    if ((a1-b1)%g!=0) {flag = true;}
    ll k = (a1+m1*c.f*((b1-a1)/g) %lm+lm)%lm; // multiply both sides to get original equation and solve for k

    if (flag) {cout << -1 << '\n';}
    else {
        x = k*x1+a; y = k*y1+b; // final position of the plane
        ll hori = x/n-1, vert = y/n-1; // amount of horizontal and vertical lines passed

        ll ynegx = (y+x-n + 2*n-1)/(2*n); // amt k satisfying y>-x+2kn+n; k>=0

        ll yposx = 0;
        if (y>x) {yposx = (y-x-n + 2*n-1)/(2*n);}
        if (y<x) {yposx = (-y+x-n + 2*n-1)/(2*n);}
        // if y>x, amt k satisfying y>x+2kn+n; k>=0
        // if y=x, 0
        // if y<x, amt k satisfying y<x+2kn-n; k<=0

        cout << hori+vert+ynegx+yposx << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}