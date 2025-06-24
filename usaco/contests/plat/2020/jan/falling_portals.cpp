#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define vec vector

struct Line {
    int slope, y, idx, q;
    double val(pair<ll,ll> x) {return (double)(x.f*slope)/x.s+y;} // returns function value at a fractional x coordinate
};
const int MAX_N = 2e5;
Line p[MAX_N], unsort[MAX_N];
pair<ll,ll> ans[MAX_N];
int n;

double isect(Line& a, Line& b) {return (double)(a.y-b.y)/(b.slope-a.slope);}

void calc() {
    sort(p,p+n,[&](const Line& a, const Line& b) {return a.idx<b.idx;});
    copy(p,p+n,unsort);
    sort(p,p+n,[&](const Line& a, const Line& b) {return a.y<b.y;}); // sort by y intercept
    vec<Line> hull; vec<pair<ll,ll>> bp; // stores the lines and breakpoints in the upper hull

    for (int i=0;i<n;i++) {
        while ((hull.size() && p[i].slope>hull.back().slope) || (hull.size()>1 && isect(hull.back(),p[i])>=isect(hull.back(),hull.end()[-2]))) {
            bp.pop_back();
            hull.pop_back();
        } // update hull

        if (hull.size()==0) {bp.pb({3e9,1});} // update breakpoints (stored as fractions)
        else {bp.pb({p[i].y-hull.back().y,hull.back().slope-p[i].slope});}
        
        hull.pb(p[i]);
        
        if (p[i].y<unsort[p[i].q].y) { // a[i]<a[q[i]]
            Line cur = unsort[p[i].q];
            
            int lo = 0, hi = hull.size()-1, mid = (lo+hi)/2, res = -1;
            while (lo <= hi) { // take intersection of line q[i] with hull by binary search
                if (cur.val(bp[mid])<=hull[mid].val(bp[mid])) {
                    res = mid;
                    lo = mid+1;
                } else {hi = mid-1;}
                mid = (lo+hi)/2;
            }
            if (res!=-1) {ans[p[i].idx] = {cur.y-hull[res].y,hull[res].slope-cur.slope};} // make sure there is an intersection with positive x
            else {ans[p[i].idx] = {-1,-1};}
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("falling.in","r",stdin);
    freopen("falling.out","w",stdout);

    cin >> n;
    for (int i=0;i<n;i++) {cin >> p[i].y;}
    for (int i=0;i<n;i++) {cin >> p[i].q; p[i].q--;}
    for (int i=0;i<n;i++) {p[i].idx = i; p[i].slope = -(i+1);}
    
    calc(); // take care of a[i]<a[q[i]]
    for (int i=0;i<n;i++) {p[i].slope *= -1; p[i].y *= -1;} // mirror across x axis
    calc(); // take care of a[i]>a[q[i]]

    for (int i=0;i<n;i++) {
        if (ans[i].f==-1) {cout << -1 << '\n';}
        else {
            ll g = gcd(ans[i].f,ans[i].s);
            cout << ans[i].f/g << '/' << ans[i].s/g << '\n';
        }
    }
}