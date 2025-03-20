#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

int solve() {
    int n; cin >> n;
    int p1 = 0, p2 = 0, u = 0;
    F0R(i,n) {
        int a; cin >> a;
        if (a!=i+1 && a!=n-i) {u++;}
        else if (a!=i+1) {p1++;}
        else if (a!=n-i) {p2++;}
    }

    if (p1<=p2) {return (u<=(p2-p1) ? 1 : 2);} // player 1 reaches middle first
    if (p2<p1) {return (u<(p1-p2) ? 0 : 2);} // player 2 reaches middle first
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int res = solve();
        if (res==1) {cout << "First\n";}
        else if (res==0) {cout << "Second\n";}
        else {cout << "Tie\n";}
    }
}