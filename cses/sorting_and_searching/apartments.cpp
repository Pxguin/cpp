#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    v<int> a(n), b(m);
    F0R(i,n) {cin >> a[i];}
    F0R(i,m) {cin >> b[i];}
    sort(all(b)); sort(all(a));

    int ptr = 0, ans = 0;
    F0R(i,n) { // ranges [x-k,x+k]
        while (ptr<m&&b[ptr]<a[i]-k) {ptr++;}
        if (ptr<m&&b[ptr]<=a[i]+k) {ptr++; ans++;} // assign this range to the earliest untaken apartment that works
    } cout << ans << '\n';
}