#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t, n, k; cin >> t >> n >> k;
    v<pii> c(n+1);
    F0R(i,n) {cin >> c[i].f >> c[i].s;}
    c[n] = {4e9,0}; n++;
    v<pii> comp;

    int last = 0;
    F0R(i,n) {
        if (c[i+1].f>c[i].f+k) {
            comp.pb({last,i});
            last = i+1;
        }
    }

    if (t==1) { // remove one cow from each component
        int ans = 0;
        for (pii x : comp) {
            ll cur = INT_MAX;
            if ((x.s-x.f+1)%2==0) {continue;}
            chmin(cur,min(c[x.f].s,c[x.s].s));
            FOR(i,x.f+1,x.s) {
                if (c[i+1].f>c[i-1].f+k && (i-x.f)%2==0) {chmin(cur,c[i].s);}
                if (c[i+1].f<=c[i-1].f+k) {chmin(cur,c[i].s);}
            } ans += cur;
        } cout << ans << '\n';
    } else { // dp to find max removed from each component
        int ans = 0;
        v<v<ll>> dp_max(n,v<ll>(2,0)); // at cow i, given even/odd number of unpaired cows
        for (pii x : comp) {
            FOR(i,x.f,x.s+1) {dp_max[i][(i-x.f+1)%2]=-1;}
            dp_max[x.f][0] = 0;

            FOR(i,x.f,x.s+1) {
                // try pairing
                chmax(dp_max[i+1][0],dp_max[i][1]);
                chmax(dp_max[i+1][1],dp_max[i][0]);

                // try not pairing
                int it = upper_bound(all(c),make_pair(c[i].f+k,100000LL))-c.begin();

                bool make_new = (i!=x.f && c[i+1].f>c[i-1].f+k);
                if (!make_new && dp_max[i][1]!=-1) { // does it cut the component into two
                    chmax(dp_max[it][!((it-i-1)%2)],dp_max[i][1]+c[i].s);
                } 
                if (dp_max[i][0]!=-1) {chmax(dp_max[it][(it-i-1)%2],dp_max[i][0]+c[i].s);}
            }
            ans += dp_max[x.s+1][0];
        } cout << ans << '\n';
    }
}