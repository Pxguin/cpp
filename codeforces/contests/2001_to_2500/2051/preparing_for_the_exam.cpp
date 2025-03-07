#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int u;
    v<int> a(m), q(n+1);
    F0R(i,m) {cin >> a[i];}
    F0R(i,k) {cin >> u; q[u]=true;} // q: boolean array storing which questions he knows

    int dontknow = 0; // which question does he not know
    F0R(i,n) {if (!q[i+1]) {dontknow=i+1;}}

    F0R(i,m) {cout << (k==n || (k==n-1 && dontknow==a[i]));} // does he know everything on test
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}