#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define vec vector

using T = pair<pii,int>;

int n;
vec<T> pts;
vec<pii> p2;
vec<bool> seen;

ll cross(pii& a, pii& b, pii& c) {return (b.f-a.f)*(c.s-a.s)-(b.s-a.s)*(c.f-a.f);}
struct cmp {
    bool operator()(const int& x, const int& y) const { // is segment a under segment b or not
        if (p2[x].f<p2[y].f) {return cross(p2[x],p2[x+n],p2[y])>0;}
        else {return cross(p2[y],p2[y+n],p2[x])<0;}
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("hillwalk.in","r",stdin);
    freopen("hillwalk.out","w",stdout);

    cin >> n;
    pts.resize(2*n); p2.resize(2*n); seen.assign(n,false);
    F0R(i,n) {
        cin >> pts[i].f.f >> pts[i].f.s;
        cin >> pts[n+i].f.f >> pts[n+i].f.s;
        pts[i].s = pts[n+i].s = i;
        p2[i] = pts[i].f; p2[i+n] = pts[i+n].f;
    }
    sort(all(pts));

    int ans = 1, cur = 0;
    set<int,cmp> active;
    F0R(i,2*n) {
        int idx = pts[i].s;
        auto[x,y] = pts[i].f;
        if (seen[idx]) { // delete from set
            auto it = active.erase(active.find(idx));
            if (idx==cur) { // if this is the end of the segment we are walking on
                if (it==active.begin()) {cur = -1;} // find earliest segment below this segment, or -1 if none exist
                else {cur = *prev(it); ans++;}
            }
        } else { // insert to set
            active.insert(idx);
            seen[idx] = true;
        }
    } cout << ans << '\n';
}
