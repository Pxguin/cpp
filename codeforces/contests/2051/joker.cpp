#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n, m, q; cin >> n >> m >> q;
    v<pii> rng = {{1,0},{m,m},{n,n-1}};

    while (q--) {
        int a; cin >> a;

        bool flag = false; int idx = 0;
        for (auto& [l,r] : rng) {
            idx++;
            if (r<l) {continue;}
            if (l<=a && a<=r) { // it's in the range
                if (l==r && idx==2) {r--;}
                if (rng[0].s==0) {flag = true;} // create [1,1] and [n,n] ranges
            } else { // it's on one side of the range
                if (a>r) {r = min(n,r+1);}
                if (a<l) {l = max(1,l-1);}
            }
        } if (flag) {rng[0].s=1; rng[2].s=n;}
        
        ll ans = 0; // calculate size of union
        if (rng[0].s<rng[0].f) {ans = rng[1].s-rng[1].f+1;}
        else {
            ans = (rng[0].s-rng[0].f+rng[2].s-rng[2].f+2)-max(0,rng[0].s-rng[2].f+1);
            if (rng[1].s>=rng[1].f && !(rng[0].s>=rng[2].f)) {
                ans += (rng[1].s-rng[1].f+1) - max(0,rng[0].s-rng[1].f+1) - max(0,rng[1].s-rng[2].f+1);
            }
        } cout << ans << ' ';
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}