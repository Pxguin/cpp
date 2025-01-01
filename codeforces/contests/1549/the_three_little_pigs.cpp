#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int MAX_A = 3e6;
int mod = 1e9+7;
v<ll> fac(MAX_A+1,0), inv(MAX_A+1,0);
v<v<ll>> ans(MAX_A+1,v<ll>(3,0));

ll mul(ll a, ll b) {return a*b%mod;}
ll sub(ll a,ll b) {return (a-b+mod)%mod;}
ll add(ll a, ll b) {return (a+b)%mod;}

int n, q;

ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) {res = mul(res,a);}
        a = mul(a,a);
        b /= 2;
    } return res;
}

ll C(ll n, ll k) {return mul(fac[n],mul(inv[k],inv[n-k]));}

void calc() {
    fac[0] = 1;
    F0R(i,MAX_A) {fac[i+1]=mul(fac[i],i+1);}
    inv[MAX_A] = exp(fac[MAX_A],mod-2);
    for (int i=MAX_A;i;i--) {inv[i-1]=mul(inv[i],i);}

    ans[3*n][0] = 1;
    for (int i=3*n-1;i;i--) { // calculating answer
        ans[i][1] = sub(ans[i+1][0],ans[i+1][1]);
        ans[i][2] = sub(ans[i+1][1],ans[i+1][2]);
        ans[i][0] = add(sub(ans[i+1][2],sub(ans[i+1][0],C(3*n,i+1))),C(3*n,i));
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> q;
    calc();

    int query;
    F0R(i,q) {
        cin >> query;
        cout << ans[query][0] << '\n';
    }
}