#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<ll> a(n+1,0), freq(n,0);
    freq[0]++;
    F0R(i,n) {
        cin >> a[i+1];
        a[i+1] += a[i];
        freq[(a[i+1]+100000000LL*n)%n]++; // group by mod n
    }
    ll ans = 0;
    F0R(i,n) {
        ans += freq[i]*(freq[i]-1)/2;
    } cout << ans << '\n';
}