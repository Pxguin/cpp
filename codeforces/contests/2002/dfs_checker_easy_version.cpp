#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n, q; cin >> n >> q;
    v<int> p(n+1), idx(n+1), leaf(n+1,0);

    F0R(i,n-1) {int a; cin >> a;}
    for (int i=0;i<n;i++) {
        cin >> p[i+1];
        idx[p[i+1]] = i+1;
    }
    v<bool> ok(n+1,false);
    ok[0] = true; leaf[0] = (n+1); idx[0] = 0;
    int tot_ok = 0;

    auto check_par = [&](int i) { // check if child is in correct position relative to its parent
        if (i>n) {return;}
        if (ok[i]) {tot_ok--;}

        int par = i/2;
        bool res = (idx[i]==idx[par]+1 || idx[i]==idx[par]+2*leaf[i]);
        ok[i] = res;
        tot_ok += res;
    };

    for (int i=1;i<=n;i++) { // initial sweep
        leaf[i] = leaf[i/2]/2;
        check_par(i);
    }
    while (q--) {
        int x, y; cin >> x >> y;
        swap(p[x],p[y]);
        x = p[x]; y = p[y];
        swap(idx[x],idx[y]);
        
        check_par(x); check_par(y); // when swapping, update them

        check_par(2*x); check_par(2*x+1); // and update their children
        check_par(2*y); check_par(2*y+1);

        cout << (tot_ok==n ? "YES" : "NO") << '\n'; // are all nodes placed correctly
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}