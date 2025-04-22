#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    char last = '0';
    int ans = 0;
    for (int i=0;i<n;i++) {
        char c; cin >> c;
        if (c!=last && c=='0') {ans += 2;}
        last = c;
    }
    if (last=='1') {ans++;}
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {solve();}
}