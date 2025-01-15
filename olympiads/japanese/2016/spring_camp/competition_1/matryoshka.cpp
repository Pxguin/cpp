#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;
    v<pii> d(n);
    F0R(i,n) {cin >> d[i].s >> d[i].f;}

    v<pair<pii,int>> qs(q);
    F0R(i,q) {
        cin >> qs[i].f.s >> qs[i].f.f; 
        qs[i].s = i;
    }
    v<int> ans(q);

    sort(all(d),[](pii& x, pii& y) {
        if (x.f==y.f) {return x.s>y.s;}
        return x.f<y.f;
    });
    sort(all(qs),greater<>());

    while (qs.size() && qs.back().f.f<d[0].f) { // get rid of these extra ones
        ans[qs.back().s]=0;
        qs.pop_back();
    }
    d.pb({2e9,2e9});

    v<int> dp;
    int last = 0;
    F0R(i,n+1) { // calculate in batches of equal height
        if (d[i].f!=d[last].f) {
            FOR(j,last,i) { // update lis array
                int r = d[j].s;
                int p = dp.size()-(lower_bound(rall(dp),r)-dp.rbegin());
                if (p==dp.size()) {dp.pb(r);} 
                else {dp[p] = r;}
            }

            while (qs.size() && qs.back().f.f<d[i].f) { // do queries
                auto [u,id] = qs.back(); qs.pop_back();
                int p = dp.size()-(lower_bound(rall(dp),u.s)-dp.rbegin());
                ans[id] = p;
            }
            last = i; i--;
        }
    }
    F0R(i,q) {cout << ans[i] << '\n';}
}