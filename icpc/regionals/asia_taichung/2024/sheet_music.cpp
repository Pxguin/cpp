#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 1e6+1;
ll fac[MAX_N+1], inv[MAX_N+1];
ll mod = 998244353;
ll mul(ll a, ll b) {return a*b%mod;}
void add(ll& a, ll b) {a = (a+b)%mod;}
ll sub(ll a, ll b) {return (a-b+mod)%mod;}

ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) {res = mul(res,a);}
        a = mul(a,a);
        b /= 2;
    } return res;
}
void calc() {
    fac[0] = 1;
    F0R(i,MAX_N) {fac[i+1] = mul(fac[i],i+1);}
    inv[MAX_N] = exp(fac[MAX_N],mod-2);
    for (int i=MAX_N;i;i--) {inv[i-1] = mul(inv[i],i);}
}

ll C(ll n, ll k) {
    return mul(fac[n],mul(inv[k],inv[n-k]));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    calc();
    int n, k; cin >> n >> k;
    chmin(k,n);
    
    v<ll> dp(n+1,0);
    dp[0] = 0;
    ll tot = 0, sum = 0, ans = 0;
    ll exp = 1;

    FOR(i,1,n+1) {
        if (i-k>=0) {add(sum,dp[i-k]);} // for prefix sums

        if (i<=k) {dp[i] = exp; exp = mul(2,exp);} // case 1
        else {dp[i] = sub(tot,sum);} // case 2
        add(tot,dp[i]);

        add(ans,mul(dp[i],C(n-1,n-i))); // add flatlines
    }
    cout << ans << '\n';
}