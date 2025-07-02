#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6, mod = 1e9+7;
bool notprime[N+1] = {false};
void calc_primes() {
    for (ll i=2;i*i<=N;i++) {
        if (!notprime[i]) {
            for (ll j=i*i;j<=N;j+=i) {notprime[j] = true;}
        }
    }
}

ll mul(ll a, ll b) {return a*b%mod;}
ll add(ll a, ll b) {return ((a+b%mod)+mod)%mod;}
ll exp(ll a, ll b) {
    ll c = 1;
    while (b) {
        if (b&1) {c = mul(c,a);}
        a = mul(a,a); b /= 2;
    } return c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    freopen("sumdiv.in","r",stdin);
    freopen("sumdiv.out","w",stdout);

    calc_primes();

    ll a, b; cin >> a >> b;
    ll ans = 1;

    for (int p=2;p<=N;p++) {
        if (notprime[p]) {continue;}
        ll n = 0;
        while (a%p==0) {n++; a /= p;} // prime factorization of A
        if (n==0) {continue;}

        n = n*(b%(mod-1))%(mod-1); // multiply by B to get factorization of A^B
        ll sum = mul(add(1,-exp(p,n+1)),exp(add(1,-p),mod-2)); // sum of divisors
        ans = mul(ans,sum);
    }

    if (a>1) { // last prime
        a %= mod;
        if (a!=1) { // mod inverse works
            ans = mul(ans,mul(add(1,-exp(a,(b%(mod-1))+1)),exp(add(1,-a),mod-2)));
        } else { // mod inverse doesn't work
            ans = mul(ans,(b+1)%mod);
        }
    }
    cout << ans << '\n';
}