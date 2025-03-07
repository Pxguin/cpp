#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define vec vector

auto parse(vec<bool>& v, vec<pii>& o) { // split up into blocks of ones and zeroes
    for (int i=0,last=-1;i<v.size();i++) {
        if (v[i]==last) {o.back().f++;}
        else {o.pb({1,v[i]});}
        last = v[i];
    }
}

bool solve() {
    int n, m; cin >> n >> m;
    vec<bool> a(n), b(m);
    vec<pii> oa, ob; // pair {x,y}, x = length of block, y = 0/1 = type of block

    for (int i=0;i<n;i++) {
        char c; cin >> c;
        a[i] = (c=='1');
    }
    for (int i=0;i<m;i++) {
        char c; cin >> c;
        b[i] = (c=='1');
    }
    parse(a,oa); parse(b,ob);

    if (b[0] && (!a[0] || ob[0].f>oa[0].f)) {return false;} // fail case: front of C is 1, but front of B is 0 (or not enough 1s at front of B)
    if (b.back() && (!a.back() || ob.back().f>oa.back().f)) {return false;} // same case, but for suffix
    if (ob.size()==1 && b[0] && oa.size()>1) {return false;} // fail case: all ones in C, but there's zeroes in B

    for (int p1=0,p2=0;p1<ob.size();p1++) {
        if (ob[p1].s==0) { // satisfy a block of zeroes
            if (oa[p2].s==1) {p2++;}

            while (ob[p1].f!=0) { // continue going to the next block of zero in B until this block in C is satisfied
                if (p2>=oa.size()) {return false;} // fail: ran out of blocks
                if (ob[p1].f<=oa[p2].f) {oa[p2].f -= ob[p1].f; ob[p1].f = 0;}
                else {ob[p1].f -= oa[p2].f; p2 += 2;}
            }
        } else { // a block of ones
            if (oa[p2].s==0) {p2++;}

            while (p2<oa.size() && oa[p2].f<ob[p1].f) {p2 += 2;} // find the next block of ones in B that can fully contain this block
            if (p2<oa.size()) {
                oa[p2].f -= ob[p1].f;
            } else {return false;} // fail: could not find a block
        }
    }
    return true; // all blocks in C are satisfied, so return true
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {cout << (solve() ? "yes" : "no") << '\n';}
}