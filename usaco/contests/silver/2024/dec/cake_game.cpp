#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    ll tot = 0;
    int n; cin >> n;
    v<ll> a(n), ps(n+1,0), ss(n+1,0);
    F0R(i,n) {cin >> a[i]; tot += a[i];}
    F0R(i,n) {ps[i+1] = ps[i]+a[i];}
    F0R(i,n) {ss[i+1] = ss[i]+a[n-i-1];}

    ll e = 0, num = n/2-1;
    F0R(i,num+1) {
        chmax(e,ps[i]+ss[num-i]); // prefix/suffix, take the maximum sum
    } cout << tot-e << ' ' << e << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {solve();}
}