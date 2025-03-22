#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

void solve() {
    int n, m; cin >> n >> m;
    vec<char> p(n+m-1);
    vec<vec<ll>> a(n,vec<ll>(m,0));
    F0R(i,n+m-2) {cin >> p[i];}
    F0R(i,n) {
        F0R(j,m) {cin >> a[i][j];}
    }
    int r = 0, c = 0;
    F0R(i,n+m-1) { // go through each cell in the path
        ll sum = 0;
        if (p[i]=='D') { // get this from the sum of the row
            F0R(j,m) {sum += a[r][j];}
            a[r][c] = -sum;
            r++;
        } else { // get this from the sum of the column
            F0R(j,n) {sum += a[j][c];}
            a[r][c] = -sum;
            c++;
        }
    }
    F0R(i,n) {F0R(j,m) {cout << a[i][j] << ' ';} cout << '\n';}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}