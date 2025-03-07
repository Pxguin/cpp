#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)

int x, y, z, k;
int turns;
ll solve(ll upg) { // simulate to find minimum attacks needed
    ll times = (upg-1)/k;
    ll hp = z-(k+k*times)*(times)/2;
    turns = ceil((double)max(0LL,hp)/upg);
    ll cost = upg*x + times*y;
    cost += ceil((double)max(0LL,hp)/upg)*y;
    return cost;
}
ll solve2(ll cmp) {
    int l = 1, h = z, m = (l+h)/2;
    ll ret = LLONG_MAX;
    while (l <= h) { // binary search on first A
        ll cand = solve(m);
        if (turns<=cmp) {h = m-1; ret = cand;}
        else {l = m+1;}
        m = (l+h)/2;
    } return ret;
}

void solve() {
    cin >> x >> y >> z >> k;
    
    ll ans = LLONG_MAX;
    int rt = ceil(sqrt(z));
    for (int i=1;i<=rt;i++) {chmin(ans,solve(i));} // fix # upgrades
    for (int i=1;i<=rt;i++) {chmin(ans,solve2(i));} // fix # attacks post-upgrades
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}