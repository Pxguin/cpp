#include <bits/stdc++.h>
#include <atcoder/math>
using namespace std;

#define ll long long
#define all(x) x.begin(),x.end()
#define vec vector

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vec<ll> a(n);
    for (int i=0;i<n;i++) {cin >> a[i];}
    sort(all(a));

    ll bag = a[0]*n, ans = (a[0]+1)%mod;
    for (int i=1;i<n;i++) {
      ll rep = a[i]-a[i-1];
      ans = (ans+rep+atcoder::floor_sum(rep,n,n-i,bag+n-i)%mod)%mod;
      bag += rep*(n-i);
    }
    cout << ans << '\n';
}