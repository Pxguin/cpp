#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n; cin >> n;

    ll rt = 1, ans = 0;
    while (rt*rt<n) {rt++;} // finding sqrt of N

    for (ll i=1;i<=rt;i++) { // brute force D up to sqrt(N)
        ll num = n/i;
        if (num<=rt) {break;}
        ans += i*num % mod;
    }
    ll ub = n;
    for (ll i=1;i<=rt;i++) { // brute force floor(N/D) up to sqrt(N)
        ll lb = n/(i+1)+1;
        ll cnt = (ub+lb)%mod *((ub-lb+1)%mod)%mod *i%mod * 500000004LL%mod;
        ans = (ans+cnt)%mod;
        ub = lb-1;
    } cout << ans << '\n';
}