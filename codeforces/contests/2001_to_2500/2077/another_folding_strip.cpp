#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector

const int mod = 998244353;
int add(ll a, ll b) {
    ll c = (a+b)%mod;
    if (c<0) {c += mod;}
    return c;
}
int mul(ll a, ll b) {return (a%mod)*(b%mod)%mod;}

void solve() {
    int n; cin >> n;
    vec<ll> a(n), ps(n+1);
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if (i%2) {
            ps[i+1] = ps[i]+a[i];
        } else {
            ps[i+1] = ps[i]-a[i];
        }
    }
    ll ans = 0;
    auto solve = [&]() {
        stack<int> mx, mx2;
        vec<int> lef(n+1), rig(n+1);
        vec<int> ps2(n+2,0);
        
        for (int i=0;i<=n;i++) {
            ps2[i+1] = add(ps2[i],ps[i]);

            while (mx.size() && ps[mx.top()]<ps[i]) {mx.pop();}
            while (mx2.size() && ps[mx2.top()]<=ps[n-i]) {mx2.pop();}
            lef[i] = (mx.size() ? mx.top() : -1)+1;
            rig[n-i] = (mx2.size() ? mx2.top() : n+1)-1;
            mx.push(i); mx2.push(n-i);
        }

        for (int i=0;i<=n;i++) {
            int sum = mul(mul(rig[i]-i+1,i-lef[i]+1),ps[i]);
            int sum2 = mul(rig[i]-i+1,add(ps2[i+1],-ps2[lef[i]]));
            ans = add(ans,add(sum,-sum2));
        }
    };
    solve();
    for (int i=0;i<n;i++) {ps[i+1] *= -1;}
    solve();
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}