#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("squares.in","r",stdin);
    freopen("squares.out","w",stdout);

    int n, k; cin >> n >> k;
    k /= 2;
    vec<pii> start, add;
    queue<int> stop;
    for (int i=0;i<n;i++) {
        int x, y; cin >> x >> y;
        start.pb({x,y});
    }
    sort(all(start));

    auto isect = [&](pii a, pii b) {
        ll x = max((min(a.f,b.f)+k)-(max(a.f,b.f)-k),0);
        ll y = max((min(a.s,b.s)+k)-(max(a.s,b.s)-k),0);
        return x*y;
    };

    multiset<pii> active;
    int check = -1, amt = 0;
    ll ans = 0;
    for (int i=0;i<n;i++) {
        while (stop.size() && start[stop.front()].f+k<=start[i].f-k) {
            active.erase(active.find(add[stop.front()]));
            stop.pop();
        }
        add.pb({start[i].s-k,start[i].s+k});
        auto it = active.lower_bound(add[i]);
        if (it!=active.end() && it->f<add[i].s) {
            check = i; amt++; // find any intersecting square
        }
        if (it!=active.begin() && prev(it)->s>add[i].f) {
            check = i; amt++;
        }
        active.insert(add[i]);
        stop.push(i);
    }
    if (check!=-1) { // find area of intersection
        for (int i=0;i<n;i++) {
            if (i==check) {continue;}
            ll a = isect(start[i],start[check]);
            if (a) {amt++; ans += a;} // upd only if there is positive intersection
        }
    }
    cout << (amt>2 ? -1 : ans) << '\n';
}
