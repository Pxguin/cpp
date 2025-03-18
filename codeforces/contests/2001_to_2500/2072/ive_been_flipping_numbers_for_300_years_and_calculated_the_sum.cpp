#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9+7;

void solve() {
    ll n, k; cin >> n >> k;

    if (n==1) {cout << (k-1)%mod << '\n'; return;}
    
    ll ans = 0;
    if (k>n) {
        ans = (k-n)%mod * n %mod;
    }
    const ll rt = max(2LL,(ll)sqrt(n));
    for (ll p=2;p<=min(rt,k);p++) {
        ll c = p, c2 = 1, cur = n;
        while (c*p<=n) {c *= p;}

        while (c!=0) {
            ll sub = min(p-1,cur/c);
            cur -= c*sub;
            ans = (ans+c2*sub)%mod;
            c /= p; c2 *= p;
        }
    }
    ll ub = min(n,k);
    if (ub>rt) {
        ans = (ans+((rt+1+ub)*(ub-rt)/2 *n %mod)) %mod;
        for (ll i=n/ub;i<=rt;i++) {
            if (ub<=rt) {break;}
            ll lb = max(rt+1,n/(i+1)+1);
            ll cnt = ub-lb+1, sum = (ub*(ub+1)*(2*ub+1)-(lb-1)*lb*(2*lb-1))/6;

            ans = (ans+(cnt*i))%mod;
            ans = (ans-(sum %mod *i)%mod +mod) %mod;
            ub = lb-1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}