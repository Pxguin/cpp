#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 2e5+2;
struct BIT {
    int b[MAX_N+1] = {0};
    void add(int i, int a) {
        for (;i<=MAX_N;i+=i&-i) {b[i] += a;}
    }
    int sum(int i) {
        int ret = 0;
        for (;i;i-=i&-i) {ret += b[i];}
        return ret;
    }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    ll k, q; cin >> q >> k;
    v<pair<int,ll>> q1(q);
    map<ll,ll> m = {{-1e18,1},{LLONG_MAX,q+2}};
    F0R(i,q) {
        cin >> q1[i].f >> q1[i].s;
        m[q1[i].s] = q1[i].s;
    }
    int it = 2;
    for (auto& x : m) {x.s = it++;}

    set<ll> bad_r = {-(ll)1e18}, bad_l = {LLONG_MAX}; // where do components break off
    BIT cur; // for range sums
    set<ll> s = {-(ll)1e18,LLONG_MAX}; // what is currently in the set

    F0R(i,q) {
        auto[t,x] = q1[i];
        if (t==1) {
            if (!s.count(x)) { // addition of x
                ll r = *s.upper_bound(x), l = *(--s.lower_bound(x));
                
                if (r-x>k) { // add/delete edge between x and r
                    bad_r.insert(x);
                } else if (bad_l.count(r)) {bad_l.erase(r);}
                if (x-l>k) { // add/del edge between x and l
                    bad_l.insert(x);
                } else if (bad_r.count(l)) {bad_r.erase(l);}

                s.insert(x);
                cur.add(m[x],1);

            } else { // deletion of x
                ll r = *s.upper_bound(x), l = *(--s.lower_bound(x));

                if (r-l>k) { // add edge between l and r
                    bad_l.insert(r); bad_r.insert(l);
                }
                if (bad_l.count(x)) {bad_l.erase(x);} // removing x altogether
                if (bad_r.count(x)) {bad_r.erase(x);}

                s.erase(x);
                cur.add(m[x],-1);
            }
        } else {
            cout << cur.sum(m[*bad_l.upper_bound(x)]-1) // num nodes between right breakpoint and left breakpoint
                    -cur.sum(m[*(--bad_r.lower_bound(x))]) << '\n';
        }
    }
}