#include <bits/stdc++.h>
using namespace std;

#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vec<int> pos(n+1);
    for (int i=0;i<n;i++) {
        int x; cin >> x;
        pos[x] = i;
    }
    int ans = 1;
    for (int i=1;i<n;i++) {ans += (pos[i]>pos[i+1]);}
    cout << ans << '\n';
}