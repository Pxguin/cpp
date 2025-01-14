#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n; cin >> n;
    int ans = 0;
    for (ll i=2;i*i<=n;i++) {
        int cnt = 0, req = 1;
        while (n%i==0) { // prime factorization
            n /= i;
            cnt++;
            if (cnt==req) { // add 1, then 2, then 3, etc.
                cnt = 0;
                req++; ans++;
            }
        }
    }
    if (n!=1) {ans++;} // at most one prime > sqrt(n)
    cout << ans << '\n';
}