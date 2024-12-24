#include <bits/stdc++.h>
using namespace std;

#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, q; cin >> n >> q;
    v<v<int>> x(n,v<int>(n,0)), y=x, z=x;
    
    int ans = 0;
    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        ans += (++x[b][c]==n) + (++y[a][c]==n) + (++z[a][b]==n); // update which vectors it affected, and add 1 to answer if that vector is empty
        cout << ans << '\n';
    }
}