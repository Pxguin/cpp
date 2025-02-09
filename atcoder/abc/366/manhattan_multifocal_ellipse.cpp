#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_C = 4e6;
ll cntx[MAX_C+1], cnty[MAX_C+1], py[MAX_C+1];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    int n, d; cin >> n >> d;
    v<pii> pts(n);
    ll dy = 0, dx = 0, r = n;
    F0R(i,n) {
        int a, b; cin >> a >> b;
        pts[i] = {a+2e6,b+2e6};
        cntx[pts[i].f]++; cnty[pts[i].s]++; 
        dy += pts[i].s; dx += pts[i].f;
    }

    if (dy<=d) {py[dy]++;}
    FOR(i,1,MAX_C+1) { // calculate manhattan dist for y
        r -= cnty[i-1];
        dy -= r; dy += n-r;
        if (dy<=d) {py[dy]++;}
    }
    F0R(i,MAX_C) {py[i+1] += py[i];}

    ll ans = 0; r = n;
    if (dx<=d) {ans += py[d-dx];}
    FOR(i,1,MAX_C+1) { // calc distances for x and add number of corresponding y
        r -= cntx[i-1];
        dx -= r; dx += n-r;
        if (dx<=d) {ans += py[d-dx];}
    } cout << ans << '\n';
}