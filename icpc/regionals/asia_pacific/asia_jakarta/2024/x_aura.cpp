#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int r, c, x; cin >> r >> c >> x;
    v<v<int>> h(r,v<int>(c));
    F0R(i,r) {
        F0R(j,c) {
            char z; cin >> z;
            h[i][j] = z-'0';
        }
    }

    v<v<ll>> dist(r,v<ll>(c,LLONG_MAX));
    dist[0][0] = 0;
    bool invalid = false;

    auto check = [&](int i, int j, int i2, int j2) {
        ll base = h[i][j]-h[i2][j2], cost = 1;
        F0R(i,x) {cost *= base;}
        if (dist[i2][j2]==LLONG_MAX) {dist[i2][j2] = dist[i][j]+cost;}
        else { // negative cycle exists
            if (cost+dist[i][j]!=dist[i2][j2]) {
                invalid = true;
            }
        }
    };

    F0R(i,r) { // calc distance from 1 to every other node
        F0R(j,c) {
            if (i!=r-1) {check(i,j,i+1,j);}
            if (i) {check(i,j,i-1,j);}
            if (j!=c-1) {check(i,j,i,j+1);}
            if (j) {check(i,j,i,j-1);}
        }
    }
    int q; cin >> q;
    while (q--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        if (invalid) {cout << "INVALID\n";}
        else {cout << -1LL*dist[r1-1][c1-1]+dist[r2-1][c2-1] << '\n';}
    }
}