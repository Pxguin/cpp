#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n, x; cin >> n >> x;
    v<ll> a(n);
    F0R(i,n) {cin >> a[i];}

    unordered_map<ll,v<pii>> rh;
    pii a12 = {-1,-1}, a34;

    for (int i=n-1;i>=2;i--) { // all pairs on rhs
        FOR(j,i+1,n) {rh[a[i]+a[j]].pb({i,j});}
    }

    FOR(j,2,n) { // breakpoint
        F0R(i,j-1) {
            if (rh[x-a[i]-a[j-1]].size()) { // check all new pairs on lhs
                a34 = rh[x-a[i]-a[j-1]][0];
                a12 = {i,j-1};
            }
        }
        FOR(i,j+1,n) {rh[a[i]+a[j]].pop_back();} // remove pairs that cross over to lhs
    }
    if (a12.f==-1) {cout << "IMPOSSIBLE";}
    else {cout << a12.f+1 << ' ' << a12.s+1 << ' ' << a34.f+1 << ' ' << a34.s+1;}
}