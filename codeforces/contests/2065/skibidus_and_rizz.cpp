#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int flip = 0;
    if (n<m) {swap(n,m); flip = 1;}

    if (n-k>m || k>n) {cout << "-1\n"; return;}
    for (int i=0;i<k;i++) {cout << flip;} // initial block of K
    for (int i=0;i<n-k;i++) {cout << !flip << flip;} // alternate characters
    for (int i=0;i<m-(n-k);i++) {cout << !flip;} // ending block
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {solve();}
}