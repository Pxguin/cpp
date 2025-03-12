#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a[101] = {0};
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        int b; cin >> b;
        a[b]++;
    }
    int ans = 0;
    for (int i=1;i<=100;i++) {
        ans += a[i]/3;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}