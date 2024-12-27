#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    v<ll> a(n);
    F0R(i,n) {cin >> a[i];}

    v<ll> ps(n+1,0);
    F0R(i,n) {ps[i+1] = ps[i]+a[i];}
    v<pii> sums;
    F0R(i,n) {FOR(j,i,n) {sums.pb({i,j});}}
    sort(all(sums),[&](pii& x, pii& y) {return ps[x.s+1]-ps[x.f]<ps[y.s+1]-ps[y.f];}); // sort by sum

    F0R(i,n) {
        v<ll> cont, non; // which ranges contain a_i and which ones don't
        for (pii x : sums) { // sort ranges into the two arrays
            if (x.f<=i && x.s>=i) {cont.pb(ps[x.s+1]-ps[x.f]);}
            else {non.pb(ps[x.s+1]-ps[x.f]);}
        }
        int p1 = 0;
        ll ans = LLONG_MAX;
        for (ll j : cont) { // 2p
            while (p1<non.size()&&non[p1]<j) {p1++;}
            if (p1<non.size()) {chmin(ans,non[p1]-j);}
            if (p1) {chmin(ans,j-non[p1-1]);}
        } cout << ans << '\n';
    }
}