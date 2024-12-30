#include <bits/stdc++.h>
using namespace std;

void solve() {
    double n, a, b, c; cin >> n >> a >> b >> c;
    int c1 = ceil(n/(a+b+c))*3, c2 = 1+ceil((n-a)/(a+b+c))*3, c3 = 2+ceil((n-a-b)/(a+b+c))*3; // candidates
    cout << min(c1,min(c2,c3)) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}