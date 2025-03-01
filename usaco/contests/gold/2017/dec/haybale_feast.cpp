#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("hayfeast.in","r",stdin);
    freopen("hayfeast.out","w",stdout);

    int n; ll m; cin >> n >> m;
    v<ll> f(n), s(n);
    F0R(i,n) {cin >> f[i] >> s[i];}

    deque<ll> q;
    int p = 0;
    ll tot = 0, ans = LLONG_MAX;
    F0R(i,n) { // iterate over left pointer
        while (p<n && tot<m) { // while total flavor <= M, increase right pointer
            tot += f[p];
            while (q.size() && q.back()<s[p]) {q.pop_back();} // sliding window maximum
            q.push_back(s[p++]);
        }
        if (tot>=m) {chmin(ans,q.front());} // update answer is flavor <= M
        if (s[i]==q.front()) {q.pop_front();} // removing left pointer from window
        tot -= f[i];
    } cout << ans << '\n';
}