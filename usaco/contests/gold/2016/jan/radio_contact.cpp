#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

ll sq(ll x) {return x*x;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("radio.in","r",stdin);
    freopen("radio.out","w",stdout);
    int n, m; cin >> n >> m;

    v<pii> pos_fj(n+2), pos_b(m+2);
    cin >> pos_fj[0].f >> pos_fj[0].s >> pos_b[0].f >> pos_b[0].s;

    string fj, b; cin >> fj >> b;
    v<v<ll>> dp(n+2,v<ll>(m+2,LLONG_MAX));

    F0R(i,n) { // calc positions of fj and bessie at any step
        pos_fj[i+1].f = pos_fj[i].f+((fj[i]=='E')-(fj[i]=='W'));
        pos_fj[i+1].s = pos_fj[i].s+((fj[i]=='N')-(fj[i]=='S'));
    }
    F0R(i,m) {
        pos_b[i+1].f = pos_b[i].f+((b[i]=='E')-(b[i]=='W'));
        pos_b[i+1].s = pos_b[i].s+((b[i]=='N')-(b[i]=='S'));
    }

    dp[0][0] = 0;
    F0R(i,n+1) {
        F0R(j,m+1) {
            ll dist = sq(pos_fj[i+1].f-pos_b[j].f)+sq(pos_fj[i+1].s-pos_b[j].s); // move fj
            chmin(dp[i+1][j],dp[i][j]+dist);

            ll dist2 = sq(pos_fj[i].f-pos_b[j+1].f)+sq(pos_fj[i].s-pos_b[j+1].s); // move bessie
            chmin(dp[i][j+1],dp[i][j]+dist2);

            ll dist3 = sq(pos_fj[i+1].f-pos_b[j+1].f)+sq(pos_fj[i+1].s-pos_b[j+1].s); // move both
            chmin(dp[i+1][j+1],dp[i][j]+dist3);
        }
    }
    cout << dp[n][m] << '\n';
}