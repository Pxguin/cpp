#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector

ll mod = 1e9+7;
ll mul(ll a, ll b) {return a*b%mod;}
ll add(ll a, ll b) {return ((a+b)%mod+mod)%mod;}

ll exp(ll a, ll b) {
    ll c = 1;
    while (b) {
        if (b&1) {c = mul(c,a);}
        a = mul(a,a); b /= 2;
    } return c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    vec<ll> ans(3,1);
    ll s2 = 1;

    for (int i=0;i<n;i++) {
        ll x, k; cin >> x >> k;

        ll prod = exp(x,k*(k+1)/2%(mod-1));
        ans[2] = mul(exp(ans[2],k+1),exp(prod,s2));

        ans[0] = mul(ans[0],k+1);
        s2 = s2*(k+1)%(mod-1);

        ll sum = mul(add(1,-exp(x,k+1)),exp(add(1,-x),mod-2));
        ans[1] = mul(ans[1],sum);
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}