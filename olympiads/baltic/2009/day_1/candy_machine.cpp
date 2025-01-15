#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<pii> candies(n);
    F0R(i,n) {
        cin >> candies[i].f >> candies[i].s;
    }
    sort(all(candies),[](pii& x, pii& y) { // sort by increasing x, then increasing y
        if (x.f+x.s==y.f+y.s) {return x.s-x.f < y.s-y.f;}
        return x.f+x.s < y.f+y.s;
    });

    v<v<pii>> ans;
    v<int> dp;
    F0R(i,n) {
        int y = candies[i].s-candies[i].f;
        int p = dp.size()-(upper_bound(dp.rbegin(),dp.rend(),y)-dp.rbegin()); // greedy strategy: find first y <= this y
        if (p==dp.size()) { // if no y exists, get a new wagon
            dp.pb(y);
            ans.pb({candies[i]});
        } else { // assign this candy to that wagon
            dp[p] = y;
            ans[p].pb(candies[i]);
        }
    }
    cout << ans.size() << '\n';
    F0R(i,ans.size()) {
        for (pii x : ans[i]) {
            cout << x.f << ' ' << x.s << ' ' << i+1 << '\n';
        }
    }
}