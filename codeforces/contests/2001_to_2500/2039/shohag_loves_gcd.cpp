#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmax(a, b) a = max(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N= 1e5;
vec<int> divs[MAX_N+1];

void solve() {
    int n, m; cin >> n >> m;
    vec<int> a(m,0);
    for (int i=0;i<m;i++) {cin >> a[i];}
    sort(all(a),greater<>());

    bool flag = false;
    vec<int> ans(n);
    for (int i=1;i<=n;i++) {
        for (int d : divs[i]) {
            chmax(ans[i-1],ans[d-1]+1); // get largest possible
        }
        if (ans[i-1]==m) {flag = true;}
    }
    if (flag) {cout << -1;}
    else {
        for (int i=0;i<n;i++) {cout << a[ans[i]] << ' ';}
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    for (int i=1;i<=MAX_N;i++) {
        for (int j=2*i;j<=MAX_N;j+=i) {
            divs[j].pb(i);
        }
    }

    int t; cin >> t;
    while (t--) {solve();}
}