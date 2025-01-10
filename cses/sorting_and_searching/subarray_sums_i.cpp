#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, x; cin >> n >> x;
    v<int> a(n);
    F0R(i,n) {cin >> a[i];}

    int p = 0, sum = a[0];
    int ans = 0;
    F0R(i,n) {
        while (p<n && sum<x) {sum += a[++p];} // incr. ptr while sum <= x
        if (sum==x) {ans++;}
        sum -= a[i];
    } cout << ans << '\n';
}