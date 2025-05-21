#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)

int tryit(int a, int b) { // blah
    int res = 0;
    while (a>1) {a = (a+1)/2; res++;}
    while (b>1) {b = (b+1)/2; res++;}
    return res;
}

void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    int ans = INT_MAX;
    
    if (a>1) {chmin(ans,tryit(n-a+1,m));} // four possible cuts
    if (a<n) {chmin(ans,tryit(a,m));}
    if (b>1) {chmin(ans,tryit(n,m-b+1));}
    if (b<m) {chmin(ans,tryit(n,b));}
    cout << ans+1 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}