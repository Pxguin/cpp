#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int mod = 998244353;
int add(int a, int b) {return (a+b)%mod;}
int mul(int a, int b) {return (ll)a*b%mod;}
int C2(int x) {return (ll)x*(x-1)/2%mod;}

pii dp[52][64][2];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;
    v<int> a(n+1,0);
    v<v<int>> occ(51,v<int>(n+1,0));
    F0R(i,n) {
        cin >> a[i+1];
        occ[a[i+1]][i+1]++;
        a[i+1] ^= a[i];
        F0R(j,51) {occ[j][i+1] += occ[j][i];}
    }

    auto upd = [](pii& to, pii from)->void {
        if (from.f==to.f) {to.s = add(to.s,from.s);}
        else if (from.f>to.f) {to = from;}
    };
    while (q--) {
        int l, r; cin >> l >> r;
        int x = a[r]^a[l-1]; // desired xorsum
        int f[51]; // occurence of each a_i
        F0R(i,51) {f[i] = occ[i][r]-occ[i][l-1];}

        memset(dp,-1,sizeof(dp));
        dp[0][0][1] = {0,1};
        
        F0R(i,51) {
            int z = (f[i]&1 ? i : 0);
            F0R(j,64) { 
                F0R(k,2) {
                    pii& cur = dp[i][j][k];
                    if (cur.f==-1) {continue;}

                    pii other = {cur.f+f[i]-1,mul(cur.s,f[i])}; // take all but one
                    pii allcur = {cur.f+f[i],cur.s}; // take all
           
                    upd(dp[i+1][z^j][k],allcur);
                    
                    if (f[i]>=1) {
                        upd(dp[i+1][z^i^j][0],other);
                    }
                    
                    if (k==1 && f[i]>=2) { // take all but two
                        pii mostcur = {cur.f+f[i]-2,mul(cur.s,C2(f[i]))};
                        upd(dp[i+1][z^j][0],mostcur);
                    }
                }
            }
        }
        if (dp[51][x][0].f==-1) {cout << -1 << '\n';}
        else {cout << dp[51][x][0].f << ' ' << dp[51][x][0].s << '\n';}
    }
}