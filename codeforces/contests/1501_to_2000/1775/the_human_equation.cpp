#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
    int n; cin >> n;
    ll sum = 0, mn = 0, mx = 0;
    F0R(i,n) {
        int a; cin >> a;
        sum += a;
        chmin(mn,sum); // min
        chmax(mx,sum); // max
    } cout << mx-mn << '\n'; // abs(max)+abs(min) = max-min
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}