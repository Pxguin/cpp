#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    for (int i=1;i<=n;i++) {
        cout << 2*i-1 << ' '; // print odd numbers
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}