#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    cout << "digit" << endl; // max: 81
    cout << "digit" << endl; // max: 16
    cout << "add -8" << endl; // max: 8
    cout << "add -4" << endl; // max: 5
    cout << "add -2" << endl; // max: 3
    cout << "add -1" << endl; // max: 1
    cout << "mul " << n << endl; // = n
    cout << "!" << endl;
    for (int i=0;i<8;i++) {int x; cin >> x;}
}

int main() {
    int t; cin >> t;
    while (t--) {solve();}
}