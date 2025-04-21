#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX_N = 1e6;
const ll mod = 1e9+7;
ll mul(ll a, ll b) {return a*b%mod;}
ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) {res = mul(res,a);}
        b /= 2; a = mul(a,a);
    } return res;
}
ll fac[MAX_N+1], inv[MAX_N+1];
void calc() {
    fac[0] = 1;
    for (int i=1;i<=MAX_N;i++) {fac[i] = mul(fac[i-1],i);}
    inv[MAX_N] = exp(fac[MAX_N],mod-2);
    for (int i=MAX_N;i;i--) {inv[i-1] = mul(inv[i],i);}
}
ll C(int n, int k) {
    if (k>n || k<0) {return 0;}
    return mul(fac[n],mul(inv[k],inv[n-k]));
}

int main() {
    calc();

    ll k, n, l; cin >> k >> n >> l;
    string s; cin >> s;

    ll rem = 0, ans = 1;
    for (int i=n-1;i>=0;i--) {
        if (s[i]=='O') {rem++;} // how many O do we have for the next M
        else {
            ans = mul(ans,C(rem,k)); // select K out of them
            rem -= k;
        }
    }
    cout << exp(ans,l) << '\n';
}