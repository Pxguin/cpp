#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

void solve() {
    int n, x; cin >> n >> x;
    vec<int> a(n);
    F0R(i,n) {cin >> a[i];}

    vec<int> r(n), ans(n+2,0); // dp
    ll tot = 0;
    for (int i=n-1,p=n-1,sum=0;i>=0;i--) {
        sum += a[i];
        while (sum>x) {sum -= a[p--];} // find maximum right point such that sum from i to that point is <= x
        r[i] = p+1;
        tot += (ans[i] = r[i]-i + ans[r[i]+1]); // update dp
    } cout << tot << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}

}