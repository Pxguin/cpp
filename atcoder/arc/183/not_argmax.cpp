#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vec vector

const int mod = 998244353, N = 500, M = 1e5;
int l[M], x[M], r[M];
int dp[N][N], cnt[N];
vec<int> l_lim[N], r_lim[N];

ll fac[N+1], inv[N+1];
ll mul(ll a, ll b) {return a*b%mod;}
void add(int& a, ll b) {a = (a+b)%mod;}
ll exp(ll a, ll b) {
    ll c = 1;
    while (b) {
        if (b&1) {c = mul(c,a);}
        a = mul(a,a); b /= 2;
    } return c;
}
void pre() {
    fac[0] = 1;
    for (int i=1;i<=N;i++) {fac[i] = mul(fac[i-1],i);}
    inv[N] = exp(fac[N],mod-2);
    for (int i=N;i;i--) {inv[i-1] = mul(inv[i],i);}
}
ll C(ll n, ll k) {
    return mul(mul(inv[n-k],inv[k]),fac[n]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    pre();

    int n, m; cin >> n >> m;
    memset(dp,0,sizeof(dp));
    for (int i=0;i<n;i++) {dp[i][i] = 1;} // base cases

    for (int i=0;i<m;i++) {
        cin >> l[i] >> r[i] >> x[i];
        --l[i]; --r[i]; --x[i];
        if (l[i]==r[i]) {dp[l[i]][l[i]] = 0;} // base cases
    }
    for (int len=1;len<n;len++) {
        for (int i=0;i<n;i++) {l_lim[i].clear(); r_lim[i].clear();}
        memset(cnt,0,sizeof(cnt));
        for (int i=0;i<m;i++) {
            if (r[i]-l[i]>len) {continue;} // delete bad ranges
            l_lim[max(0,r[i]-len)].pb(x[i]); // l_lim/r_lim: range of u for which [u,u+len] contains [l_i,r_i]
            r_lim[l[i]].pb(x[i]);
        }

        for (int u=0;u<n-len;u++) {
            for (int x : l_lim[u]) { // add ranges that are now contained inside [u,u+len]
                cnt[x]++;
            }

            for (int mx=u;mx<=u+len;mx++) { // fix max
                if (cnt[mx]==0) { // only works if this is valid
                    int lef = (mx==u ? 1 : dp[u][mx-1]), rig = (mx==u+len ? 1 : dp[mx+1][u+len]);
                    add(dp[u][u+len],mul(C(len,mx-u),mul(lef,rig)));
                }
            }
            
            for (int x : r_lim[u]) { // delete ranges no longer contained inside [u,u+len]
                cnt[x]--;
            }
        }
    }
    cout << dp[0][n-1] << '\n';
}