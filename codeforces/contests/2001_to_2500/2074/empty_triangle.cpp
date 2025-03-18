#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand2() {return uniform_int_distribution<int>(0,2)(rng);}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a = 1, b = 2, c = 3;
        while (true) {
            cout << "? " << a << ' ' << b << ' ' << c << endl;
            int d; cin >> d;
            if (d==0) {cout << "! " << a << ' ' << b << ' ' << c << endl; break;}
            if (d==-1) {return 0;}
            int r = rand2();
            if (r==0) {a = d;}
            else if (r==1) {b = d;}
            else if (r==2) {c = d;}
        }
    }
}