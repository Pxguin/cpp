#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int n;
v<int> segtree_min, segtree_max, segtree_ans;

void upd(int idx, int val, int l=0, int r=n-1, int cur=1) {
    if (l==r) {
        segtree_min[cur] = val;
        segtree_max[cur] = val;
    } else {
        int m = (l+r)/2;
        if (idx<=m) {upd(idx,val,l,m,2*cur);}
        else {upd(idx,val,m+1,r,2*cur+1);}
        segtree_min[cur] = min(segtree_min[2*cur],segtree_min[2*cur+1]);
        segtree_max[cur] = max(segtree_max[2*cur],segtree_max[2*cur+1]);
    } segtree_ans[cur] = max(segtree_max[2*cur+1]-segtree_min[2*cur],max(segtree_ans[2*cur],segtree_ans[2*cur+1]));
}

void solve() {
    int q; cin >> n >> q;
    v<int> a(n);
    v<pii> qs(q);
    segtree_min.assign(8*n,0);
    segtree_max.assign(8*n,0);
    segtree_ans.assign(8*n,0);
    F0R(i,n) {cin >> a[i];}
    F0R(i,q) {cin >> qs[i].f >> qs[i].s;}

    v<int> ans(q+1,0);
    F0R(z,2) {
        F0R(i,n) {
            upd(i,a[i]-i);
        }
        chmax(ans[0],segtree_ans[1]);
        F0R(i,q) {
            upd(qs[i].f-1,qs[i].s-(qs[i].f-1));
            qs[i].f = n-qs[i].f+1;
            chmax(ans[i+1],segtree_ans[1]);
        }

        reverse(all(a));
    }
    F0R(i,q+1) {cout << ans[i] << '\n';}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}