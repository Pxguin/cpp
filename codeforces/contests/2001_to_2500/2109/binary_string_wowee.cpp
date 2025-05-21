#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 998244353;
const int MAX_N = 501;
ll fac[MAX_N], inv[MAX_N], dp[MAX_N][MAX_N];
bool s[MAX_N];
ll mul(ll a, ll b) {return a*b%mod;}
void add(ll& a, ll b) {a = (a+b)%mod;}
ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b%2) {res = mul(res,a);}
        b /= 2; a = mul(a,a);
    } return res;
}

void pre() {
    fac[0] = 1;
    for (int i=1;i<=MAX_N;i++) {fac[i] = mul(fac[i-1],i);}
    inv[MAX_N] = exp(fac[MAX_N],mod-2);
    for (int i=MAX_N;i;i--) {inv[i-1] = mul(inv[i],i);}
}
ll C(int n, int k) {
    if (k>n) {return 0;}
    return mul(fac[n],mul(inv[k],inv[n-k]));
}

void solve() {
    int n, k; cin >> n >> k;
    for (int i=0;i<n;i++) {
        char c; cin >> c;
        s[i+1] = (c=='1');
    }

    memset(dp,0,sizeof(dp));
    dp[n][0] = 1;
    
    for (int i=n;i;i--) {
        for (int tot=0;tot<=k;tot++) {
            for (int cur=0;cur<=tot;cur++) {
                if (s[i]) { // all at odd indices (0 indexed)
                    add(dp[i-1][tot],mul(dp[i][tot-cur],C(tot/2,cur)));
                } else { // all at even indices
                    add(dp[i-1][tot],mul(dp[i][tot-cur],C((tot+1)/2,cur)));
                }
            }
        }
    } cout << dp[0][k] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    pre();

    int t; cin >> t;
    while (t--) {solve();}
}