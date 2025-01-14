#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("cowjog.in","r",stdin);
    freopen("cowjog.out","w",stdout);

    ll n, t; cin >> n >> t;
    v<pii> cows;
    F0R(i,n) {
        ll p, sp; cin >> p >> sp;
        cows.pb({p,sp*t+p}); // range for this cow
    }
    reverse(all(cows));

    v<ll> lnds;
    F0R(i,n) {
        int p = upper_bound(all(lnds),cows[i].s)-lnds.begin();
        if (p==lnds.size()) {lnds.pb(cows[i].s);}
        else {lnds[p] = cows[i].s;}
    } cout << lnds.size() << '\n';
}