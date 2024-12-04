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
        FOR(j,4,m+4) { // haha2
            if (g[i][j]=='A') {
                ans += (((g[i-1][j-1]=='M'&&g[i+1][j+1]=='S')||(g[i-1][j-1]=='S'&&g[i+1][j+1]=='M'))
                && ((g[i+1][j-1]=='M'&&g[i-1][j+1]=='S')||(g[i+1][j-1]=='S'&&g[i-1][j+1]=='M')));
            }
        }
    } cout << ans << '\n';
}