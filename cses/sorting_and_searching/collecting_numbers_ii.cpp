#include <bits/stdc++.h>
using namespace std;

#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    vec<int> pos(n+1), arr(n+1);
    for (int i=0;i<n;i++) {
        int x; cin >> x;
        arr[i+1] = x;
        pos[x] = i+1;
    }
    int ans = 1;
    for (int i=1;i<n;i++) {ans += (pos[i]>pos[i+1]);}

    auto upd = [&](int a, int b, int m) {
        if (b!=n) {ans += m*(pos[b]>pos[b+1]);}
        if (a!=1) {ans += m*(pos[a-1]>pos[a]);}
        ans += m*(pos[b-1]>pos[b]);
        if (a!=b-1) {ans += m*(pos[a]>pos[a+1]);}
    };

    for (int i=0;i<m;i++) {
        int a1, b1; cin >> a1 >> b1;
        int a = arr[a1], b = arr[b1];
        swap(arr[a1],arr[b1]);
        if (a>b) {swap(a,b);}
        upd(a,b,-1);
        swap(pos[a],pos[b]);
        upd(a,b,1);
        cout << ans << '\n';
    }
}