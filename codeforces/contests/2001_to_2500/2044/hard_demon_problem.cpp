#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n, q; cin >> n >> q;
    v<v<int>> m(n+1,v<int>(n+1));

    v<v<ll>> basic_ps(n+1,v<ll>(n+1,0));
    F0R(i,n) {
        F0R(j,n) {
            cin >> m[i+1][j+1];
            basic_ps[i+1][j+1] = m[i+1][j+1]+basic_ps[i][j+1]+basic_ps[i+1][j]-basic_ps[i][j];
        }
    }

    v<v<ll>> row_ps(n+1,v<ll>(n+1,0)), col_ps = row_ps;
    F0R(i,n) {
        F0R(j,n) {
            row_ps[i+1][j+1] = ((i+1)*m[i+1][j+1])+row_ps[i][j+1]+row_ps[i+1][j]-row_ps[i][j];
            col_ps[i+1][j+1] = ((j+1)*m[i+1][j+1])+col_ps[i][j+1]+col_ps[i+1][j]-col_ps[i][j];
        }
    }

    int r1, c1, r2, c2;
    auto get = [&](v<v<ll>>& ps) {
        return ps[r2][c2]-ps[r1-1][c2]-ps[r2][c1-1]+ps[r1-1][c1-1];
    };

    while (q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        r1++; // calculate row sum 1 row down
        ll row_sum = (r1>r2 ? 0 : get(row_ps)-(r1-1)*get(basic_ps));
        r1--; // calculate column sum normally
        ll col_sum = get(col_ps)-(c1-1)*get(basic_ps);

        cout << col_sum+(c2-c1+1)*row_sum << ' ';
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}