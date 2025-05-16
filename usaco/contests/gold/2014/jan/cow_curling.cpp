#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define vec vector

pii operator-(pii x, pii y) {return {x.f-y.f,x.s-y.s};}
ll cross(pii x, pii y) {return x.f*y.s-x.s*y.f;} // cw: neg
ll cross(pii x, pii y, pii z) {return cross(x-z,y-z);}

int main() {
    freopen("curling.in","r",stdin);
    freopen("curling.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vec<pii> p(n), p2(n);
    for (int i=0;i<n;i++) {cin >> p[i].f >> p[i].s;}
    for (int i=0;i<n;i++) {cin >> p2[i].f >> p2[i].s;}

    sort(all(p)); sort(all(p2));
    
    int ans1 = 0, ans2 = 0;
    auto get_hull = [&]() {
        vec<pii> lhull, uhull;
        for (int i=0;i<n;i++) {
            while (lhull.size()>1 && cross(p[i],lhull.back(),lhull[lhull.size()-2])>=0) { // compute lower hull
                lhull.pop_back();
            } lhull.pb(p[i]);
        }
        if (lhull.size()>1 && lhull.back().f==lhull[lhull.size()-2].f) {lhull.pop_back();} // remove vertically collinear points
        for (int i=n-1;i>=0;i--) {
            while (uhull.size()>1 && cross(p[i],uhull.back(),uhull[uhull.size()-2])>=0) { // compute upper hull
                uhull.pop_back();
            } uhull.pb(p[i]);
        }
        if (uhull.size()>1 && uhull.back().f==uhull[uhull.size()-2].f) {uhull.pop_back();} // remove vertically collinear
        reverse(all(uhull));

        uhull.pb(uhull.back()); lhull.pb(lhull.back()); // make sure hull size is >1

        int pt1 = 0, pt2 = 0, pt3 = 0;
        while (pt3<n && p2[pt3].f<lhull[pt1].f) {pt3++;} // ignore all points to the left of the hull

        while (pt3<n && pt1<uhull.size()-1) { // sweep line
            if (uhull[pt1+1].f<p2[pt3].f) {pt1++;} // increment upper hull pointer
            else if (lhull[pt2+1].f<p2[pt3].f) {pt2++;} // increment lower hull pointer
            else {
                ll ux = uhull[pt1+1].f-uhull[pt1].f, uy = uhull[pt1+1].s-uhull[pt1].s;
                ll lx = lhull[pt2+1].f-lhull[pt2].f, ly = lhull[pt2+1].s-lhull[pt2].s;

                ll hi = (uhull[pt1].s+floor(((double)p2[pt3].f-uhull[pt1].f)*uy/max(1LL,ux)));
                ll lo = (lhull[pt2].s+ceil(((double)p2[pt3].f-lhull[pt2].f)*ly/max(1LL,lx)));
                // calculate the max y and min y at this x coordinate on the hull
                ans1 += (lo<=p2[pt3].s && p2[pt3].s<=hi); // if the point is contained
                pt3++;
            }
        }
    };
    get_hull();
    swap(ans1,ans2); swap(p,p2);
    get_hull();

    cout << ans2 << ' ' << ans1 << '\n';
}