#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n; cin >> n;
    v<int> a(n);
    F0R(i,n) {cin >> a[i];}
    
    int ans = 0;
    F0R(i,n) {
        int pos = (i+1)&1;
        chmax(ans,a[i]+(n+pos)/2); // get max size depending on position of this element
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}