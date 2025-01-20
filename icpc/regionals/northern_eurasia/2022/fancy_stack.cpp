#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 5000;
ll fac[MAX_N+1], inv[MAX_N+1];
int mod = 998244353;
void add(int& a, int b) {a = (a+b)%mod;}
int mul(ll a, ll b) {return a*b%mod;}

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
    if (k>n) {return 0;}
    return mul(fac[n],mul(inv[k],inv[n-k]));
}

int dp[MAX_N+1][MAX_N/2+1][2];

void solve() {
    int n; cin >> n;
    v<int> a(n);
    v<int> ok(n,-1);

    int last = -1;
    F0R(i,n) { // find groups
        cin >> a[i];
        if (i==0 || a[i]!=a[i-1]) {
            ok[i] = true;
            if (last!=-1) {ok[last] = i;}
            last = i;
        }
    } ok[last] = n;

    F0R(i,n+1) {F0R(j,n/2+1) {F0R(k,2) {dp[i][j][k] = 0;}}}
    if (ok[n-1]!=-1) {dp[n-1][1][0] = 1;} // base case

    for (int i=n-2;i>=0;i--) {
        if (ok[i]==-1) {continue;}
        int amt = ok[i]-i;
        for (int j=0;j<=n/2;j++) {
            if (j>0 && j-1+amt-1<=n/2) { // add all except one to A, none to top
                int namt = amt-1;
                dp[i][j][0] = mul(dp[ok[i]][j-1+namt][0],C(j-2+namt,namt));
            }
            if (j+amt<=n/2) { // add all to A, none to B
                add(dp[i][j][0],mul(dp[ok[i]][j+amt][0],C(j+amt-1,amt))); 
                dp[i][j][1] = mul(dp[ok[i]][j+amt][0],C(j+amt-1,amt-1));
                add(dp[i][j][1],mul(dp[ok[i]][j+amt][1],C(j+amt,amt)));
            }
        }
    } 
    
    cout << dp[0][0][1] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    calc();
    int t; cin >> t;
    while (t--) {solve();}
}