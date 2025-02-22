#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    v<int> a(n);
    F0R(i,n) {cin >> a[i];}

    const int MAX_N = 2e6;
    int cnt[MAX_N] = {0};
    set<int> left;
    F0R(i,MAX_N) {left.insert(i);}

    F0R(i,m) { // initial window of K
        if (++cnt[a[i]]==1) {left.erase(a[i]);}
    }
    int ans = *left.begin();
    FOR(i,m,n) {
        if (++cnt[a[i]]==1) {left.erase(a[i]);} // insert new element at right of window
        if (--cnt[a[i-m]]==0) {left.insert(a[i-m]);} // delete element at left of window
        chmin(ans,*left.begin()); // get mex of window
    } cout << ans << '\n';
}