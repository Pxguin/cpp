#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

ll mod = 998244353;
void add(ll& a, ll b) {a = (a+b)%mod;}

const int MAX_LEN = 17;
v<ll> fac(MAX_LEN+1,0), inv(MAX_LEN+1,0);
ll mul(ll a, ll b) {return a*b%mod;}
ll dp[100001][17] = {0};

ll exp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b&1) {res = mul(res,a);}
		b /= 2; a = mul(a,a);
	} return res;
}

void calc() { // get factorial inverses
	fac[0] = 1;
	F0R(i,MAX_LEN) {fac[i+1]=mul(fac[i],i+1);}
	inv[MAX_LEN] = exp(fac[MAX_LEN],mod-2);
	for (int i=MAX_LEN;i;i--) {inv[i-1]=mul(i,inv[i]);}
}

void solve() {
    int k, n; cin >> k >> n;
    
    cout << n << ' '; // len (# of non-1 elements) = 0
    FOR(i,2,k+1) { // fix product
        ll ans = 0;
        F0R(len,17) { // fix len
            ll num = 1;
            FOR(z,n-len+1,n+2) { // rest of array is 1 (binomial coefficient sum)
                num = mul(num,z);
            }
            
            add(ans,mul(num,mul(inv[len+1],dp[i][len]))); // evaluate stuff
        } cout << ans << ' ';
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    dp[1][0] = 1; // dp[i][j] (num ordered ways to factorize i with j factors)
    FOR(i,1,100001) {
        F0R(j,16) {
            for (int nxt=2*i;nxt<=100000;nxt+=i) {
                add(dp[nxt][j+1],dp[i][j]);
            }
        }
    }
    calc();

    int t; cin >> t;
    while (t--) {solve();}
}