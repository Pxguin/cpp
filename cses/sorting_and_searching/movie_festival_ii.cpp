#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;
    v<pii> a(n);
    F0R(i,n) {cin >> a[i].s >> a[i].f;}
    sort(all(a)); // sort by ending time

    multiset<pii> ppl;
    F0R(i,n) {
        int mov = 1;
        auto it = ppl.upper_bound({a[i].s,INT_MAX}); // latest ending time
        if (it!=ppl.begin()) {
            mov = (--it)->s+1;
            ppl.erase(it);
        } 
        if (ppl.size()<k) {ppl.insert({a[i].f,mov});} // restrict size to K
    }
    int ans = 0;
    for (pii x : ppl) {ans += x.s;}
    cout << ans << '\n';
}