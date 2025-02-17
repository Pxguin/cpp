#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<int> a(2*n);
    v<ll> sum(2*n);
    F0R(i,n) {cin >> a[i]; a[i+n] = a[i];}

    deque<ll> mn;
    ll m = (n+1)/2, ans = 0;
    F0R(i,m) {sum[m-1] += a[i];}
    mn.push_back(sum[m-1]);

    FOR(i,m,2*n) {
        sum[i] = sum[i-1]; // first compute the sliding window sum, S_i
        sum[i] += a[i]-a[i-m];

        if (i>=2*m-1 && mn.front()==sum[i-m]) {mn.pop_front();} // compute the min sliding window (for S_i)
        while (mn.size() && mn.back()>sum[i]) {mn.pop_back();}
        mn.push_back(sum[i]);
        if (i>=2*m-1) {ans = max(ans,mn.front());}
    } cout << ans << '\n';
}