#include <bits/stdc++.h>
using namespace std;

#define vec vector

bool solve() {
    int n; cin >> n;
    vec<int> a(n);
    int sum = 0;
    for (int i=0;i<n;i++) {cin >> a[i]; sum += a[i];}

    for (int i=0;i<n-1;i++) {if (a[i]==0 && a[i+1]==0) {return false;}}
    return (sum!=0&&sum!=n);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {cout << (solve() ? "NO" : "YES") << '\n';}
}