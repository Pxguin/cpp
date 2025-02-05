#include <bits/stdc++.h>
using namespace std;

using T = __int128;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

pii operator-(const pii& a, const pii& b) {return {a.f-b.f,a.s-b.s};}
T cross(pii a, pii b) {return (T)a.f*b.s-(T)a.s*b.f;} // i.e. orientation
T cross(pii& ref, pii& a, pii& b) {return cross(a-ref,b-ref);}

T dist(pii& a) {return (T)a.f*a.f+(T)a.s*a.s;}

v<pii> pts;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;

    ll mn1 = 1e17, mx1 = -1e17;
    F0R(i,n) {
        ll x, y; cin >> x >> y;
        pts.pb({-x,y-x*x});
        chmin(mn1,pts.back().f);
        chmax(mx1,pts.back().f);
    }

    pts.pb({mn1,-1e17}); // add two more points (to effectively skip over the lower hull)
    pts.pb({mx1,-1e17});

    int d = 3;
    if (mn1==mx1) {d = 2;}
    n += 2;

    int mn = min_element(all(pts))-pts.begin(); // convex hull
    v<int> idx;
    F0R(i,n) {if (pts[i]!=pts[mn]) {idx.pb(i);}}

    sort(all(idx),[&](int a, int b) {
        pii x = pts[a]-pts[mn], y = pts[b]-pts[mn];
        T res = cross(x,y); // sort by polar angle, tiebreak by dist
        return (res!=0 ? res>0 : dist(x)<dist(y));
    });

    v<int> hull = {mn};
    for (int i : idx) { // find number of points in convex hull (no collinear edges)
        while (hull.size()>1 && cross(pts[hull[hull.size()-2]],pts[hull.back()],pts[i])<=0) {
            hull.pop_back();
        } hull.pb(i);
    }
    cout << (int)hull.size()-d << '\n'; // size of hull (minus some constant) is answer
}