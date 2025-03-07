#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

void solve() {
    int n; cin >> n;
    v<pair<pii,int>> a(n);
    v<int> l(n,0), r(n,0);
    F0R(i,n) {cin >> a[i].f.f >> a[i].f.s; a[i].s = i;}

    multiset<int> left, right;
    sort(all(a),[](pair<pii,int> x, pair<pii,int> y) { // increasing l, decreasing r (if ties)
        return (x.f.f!=y.f.f ? (x.f.f<y.f.f) : x.f.s>y.f.s);
    });
    F0R(i,n) {
        if (i==n-1 || a[i+1].f!=a[i].f) { // only process distinct ranges
            auto it = right.lower_bound(a[i].f.s); // find closest right ptr
            if (it!=right.end()) {r[a[i].s] = *it;}
        }
        right.insert(a[i].f.s);
    }

    sort(all(a),[](pair<pii,int> x, pair<pii,int> y) { // same thing on left side
        return (x.f.s!=y.f.s ? (x.f.s>y.f.s) : x.f.f<y.f.f);
    });
    F0R(i,n) {
        if (i==n-1 || a[i+1].f!=a[i].f) {
            auto it = left.upper_bound(a[i].f.f);
            if (it!=left.begin()) {l[a[i].s] = *(--it);}
        }
        left.insert(a[i].f.f);
    }
    
    sort(all(a),[](pair<pii,int> x, pair<pii,int> y) {return (x.s<y.s);});
    F0R(i,n) {
        if (l[i]&&r[i]) {cout << (r[i]-l[i]+1)-(a[i].f.s-a[i].f.f+1) << '\n';}
        else {cout << 0 << '\n';}
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}