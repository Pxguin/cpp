#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

struct Segment {
    int x1, x2, y1, y2, idx;
    pii p1, p2;
    Segment(int x1, int y1, int x2, int y2, int idx) : 
    x1(x1), y1(y1), x2(x2), y2(y2), idx(idx), p1({x1,y1}), p2({x2,y2}) {};
};
bool o(pii a, pii b, pii c) { // orientation of points a,b,c
    return ((c.s-a.s)*(b.f-a.f)-(b.s-a.s)*(c.f-a.f)>0 ? true : false);
}
bool on(pii a, pii c, pii b) { // is point b on segment AC
    return ((b.f>=min(a.f,c.f)&&b.f<=max(a.f,c.f)) 
    && (b.s>=min(a.s,c.s)&&b.s<=max(a.s,c.s))
    && ((c.s-a.s)*(b.f-a.f)==(b.s-a.s)*(c.f-a.f)));
}
bool isect(pii a, pii b, pii c, pii d) { // intersection test (including collinear case)
    if (o(a,b,c)!=o(a,b,d) && o(c,d,a)!=o(c,d,b)) {return true;}
    if (on(a,b,c)||on(a,b,d)) {return true;}
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("cowjump.in","r",stdin);
    freopen("cowjump.out","w",stdout);
    
    int n; cin >> n;
    v<Segment> s;
    F0R(i,n) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (a>c) {swap(a,c); swap(b,d);} // so that x_1<x_2
        s.pb(Segment(a,b,c,d,i));
    }
    v<pair<pii,int>> events;
    F0R(i,n) {
        events.pb({{s[i].x1,0},i});
        events.pb({{s[i].x2,1},i});
    }
    sort(all(events));

    set<pii> active;
    int s1 = -1, s2 = -1, flag = 0;

    auto test = [&](set<pii>::iterator i1, set<pii>::iterator i2) { // test for intersection given two set iterators
        Segment i = s[i1->s], j = s[i2->s];
        if (isect(i.p1,i.p2,j.p1,j.p2)) {
            s1 = i1->s; s2 = i2->s;
            flag = true;
        }
    };

    for (pair<pii,int> e : events) {
        if (flag) {break;}
        auto[z,idx] = e;
        auto[x,t] = z;
        
        if (t) { // delete
            auto it = active.lower_bound({s[idx].y1,idx});
            it = active.erase(it);
            if (it!=active.begin()&&it!=active.end()) {
                test(it,prev(it));
            }
        } else { // insert
            auto it = active.insert({s[idx].y1,idx}).f;
            if (it!=active.begin()) {
                test(it,prev(it));
            }
            if (it!=prev(active.end())) {
                test(it,next(it));
            }
        }
    }
    if (s1>s2) {swap(s1,s2);}
    int c1 = 0, c2 = 0;
    F0R(i,n) { // brute force for our two candidates
        c1 += isect(s[s1].p1,s[s1].p2,s[i].p1,s[i].p2);
        c2 += isect(s[s2].p1,s[s2].p2,s[i].p1,s[i].p2);
    }
    if (c2>c1) {cout << s2+1 << '\n';}
    else {cout << s1+1 << '\n';}
}