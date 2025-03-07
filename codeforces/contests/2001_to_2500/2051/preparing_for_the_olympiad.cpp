#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n; cin >> n;
    v<int> a(n), b(n+1,0);
    F0R(i,n) {cin >> a[i];}
    F0R(i,n) {cin >> b[i];}

    int ans = 0;
    F0R(i,n) {ans += max(0,a[i]-b[i+1]);} // if a[i]>b[i+1] then train on this day, otherwise don't train
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}