#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(),x.end()
#define v vector

void solve() {
    ll n, k; cin >> n >> k;
    v<ll> a(n);
    ll sum = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        sum += a[i];
    } sort(all(a));

    ll ans = max(0LL,sum-k); // 0 set operations

    for (int i=n-1;i;i--) { // n-i set operations (set from maximum)
        sum -= a[i]-a[0];
        ans = min(ans,n-i + max(0LL,(sum-k+(n-i))/(n-i+1))); // calc min decrease needed to get sum <= k
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}