#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int B = 450, MAX_N = 2e5, MAX_A = 1e6;

struct Query {
    int l, r, id;
    Query(int l1, int r1, int id1) : l(l1), r(r1), id(id1) {}
    Query() {}
    const bool operator<(const Query& o) const {
        if (l/B==o.l/B) {return ((l/B)%2==0 ? r<o.r : r>o.r);}
        else {return l<o.l;}
    }
};

int cnt[MAX_A+1] = {0}, a[MAX_N];
Query q[MAX_N];
ll ans[MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, t; cin >> n >> t;
    for (int i=0;i<n;i++) {cin >> a[i];}
    
    for (int i=0;i<t;i++) {
        cin >> q[i].l >> q[i].r; q[i].id = i;
        q[i].l--; q[i].r--;
    } sort(q,q+t);

    int cl = 0, cr = 0;
    ll cur = a[0]; cnt[a[0]]++;

    for (int i=0;i<t;i++) { // mo's
        while (cr<q[i].r) {
            cr++;
            cnt[a[cr]]++;
            cur += (ll)(2*cnt[a[cr]]-1)*a[cr];
        }
        while (cl>q[i].l) {
            cl--;
            cnt[a[cl]]++;
            cur += (ll)(2*cnt[a[cl]]-1)*a[cl];
        }
        while (cr>q[i].r) {
            cur -= (ll)(2*cnt[a[cr]]-1)*a[cr];
            cnt[a[cr]]--;
            cr--;
        }
        while (cl<q[i].l) {
            cur -= (ll)(2*cnt[a[cl]]-1)*a[cl];
            cnt[a[cl]]--;
            cl++;
        }
        ans[q[i].id] = cur;
    }
    for (int i=0;i<t;i++) {cout << ans[i] << '\n';}
}