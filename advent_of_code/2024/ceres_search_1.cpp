#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    v<v<char>> g(n+8,v<char>(m+8,'0'));
    F0R(i,n) {
        F0R(j,m) {
            cin >> g[i+4][j+4];
        }
    }
    int ans = 0;
    FOR(i,4,n+4) {
        FOR(j,4,m+4) { // haha
            ans += (g[i][j]=='X'&&g[i][j+1]=='M'&&g[i][j+2]=='A'&&g[i][j+3]=='S');
            ans += (g[i][j]=='X'&&g[i+1][j]=='M'&&g[i+2][j]=='A'&&g[i+3][j]=='S');
            ans += (g[i][j]=='X'&&g[i][j-1]=='M'&&g[i][j-2]=='A'&&g[i][j-3]=='S');
            ans += (g[i][j]=='X'&&g[i-1][j]=='M'&&g[i-2][j]=='A'&&g[i-3][j]=='S');
            ans += (g[i][j]=='X'&&g[i+1][j+1]=='M'&&g[i+2][j+2]=='A'&&g[i+3][j+3]=='S');
            ans += (g[i][j]=='X'&&g[i+1][j-1]=='M'&&g[i+2][j-2]=='A'&&g[i+3][j-3]=='S');
            ans += (g[i][j]=='X'&&g[i-1][j+1]=='M'&&g[i-2][j+2]=='A'&&g[i-3][j+3]=='S');
            ans += (g[i][j]=='X'&&g[i-1][j-1]=='M'&&g[i-2][j-2]=='A'&&g[i-3][j-3]=='S');
        }
    } cout << ans << '\n';
}