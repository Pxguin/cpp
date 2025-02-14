#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<int> a(n), b(n), c(n);
    F0R(i,n) {cin >> a[i];}
    F0R(i,n) {cin >> b[i];}
    F0R(i,n) {cin >> c[i];}
    sort(all(a)); sort(all(b)); sort(all(c));

    ll ans = 0;
    v<ll> dp(n+1,0);
    
    for (int i=0,p=0;i<n;i++) {
        while (p<n && c[p]<=b[i]) {p++;}
        dp[i] = n-p;
    }
    for (int i=n-1;i>=0;i--) {dp[i] += dp[i+1];}
    for (int i=0,p=0;i<n;i++) {
        while (p<n && b[p]<=a[i]) {p++;}
        ans += dp[p];
    } cout << ans << '\n';
}