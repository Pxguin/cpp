#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, a, b, c; cin >> m >> a >> b >> c;
    int seated = min(m,a)+min(m,b); // assign monkeys of type a and b first
    cout << min(2*m-seated,c)+seated << '\n'; // assign monkeys of type c
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}