#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9+7;
const int MAX_N = 2e3, MAX_C = 1e3;
ll mul(ll a, ll b) {return a*b%mod;}
ll add(ll a, ll b) {return (a+b+mod)%mod;}
ll exp(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) {r = mul(r,a);}
        b /= 2; a = mul(a,a);
    } return r;
}
ll fac[MAX_N+1], inv[MAX_N+1];
void calc() {
    fac[0] = 1;
    for (int i=1;i<=MAX_N;i++) {fac[i] = mul(fac[i-1],i);}
    inv[MAX_N] = exp(fac[MAX_N],mod-2);
    for (int i=MAX_N;i;i--) {inv[i-1] = mul(inv[i],i);}
}
ll C(int n, int k) {return (k>n ? 0 : mul(fac[n],mul(inv[k],inv[n-k])));}

int x[MAX_N], y[MAX_N], b[MAX_N], ps[MAX_C+1][MAX_C+1], isect[MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    calc();
    int n, m, r; cin >> n >> m >> r;
    for (int i=0;i<n;i++) {
        cin >> x[i] >> y[i] >> b[i];
        ps[x[i]][y[i]]++;
    }
    for (int i=1;i<=MAX_C;i++) {
        for (int j=1;j<=MAX_C;j++) {
            ps[i][j] += ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1];
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            isect[i] += (max(abs(x[j]-x[i]),abs(y[j]-y[i]))<=r);
        }
    }
 
    ll ans = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            int kill_both = 0;
            int x1 = max(1,max(x[i]-r,x[j]-r)), x2 = min(MAX_C,min(x[i]+r,x[j]+r));
            int y1 = max(1,max(y[i]-r,y[j]-r)), y2 = min(MAX_C,min(y[i]+r,y[j]+r));
            if (x1<=x2 && y1<=y2) { // calc amount of snakes that can kill both
                kill_both = ps[x2][y2]-ps[x1-1][y2]-ps[x2][y1-1]+ps[x1-1][y1-1];
            }
            // case 1: use at least one from kill both
            ll amt1 = add(C(n,m),-C(n-kill_both,m));

            // case 2: use at least one from pool that can kill only i, and same for j, and none from pool that can kill both
            ll amt2 = 0;
            if (isect[i]!=kill_both && isect[j]!=kill_both && n-kill_both>=m) { // inclusion exclusion
                ll no_i = C(n-isect[i],m), no_j = C(n-isect[j],m);
                ll no_both = C(n-isect[i]-isect[j]+kill_both,m);
                amt2 = add(C(n-kill_both,m),add(-add(no_i,no_j),no_both));
            }
            
            ans = (ans+mul((amt1+amt2)%mod,mul(b[i],b[j])))%mod; // add (amount plans that kill both) * b[i] * b[j]
        }
    } cout << ans << '\n';
}