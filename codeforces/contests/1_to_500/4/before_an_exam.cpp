#include <bits/stdc++.h>
using namespace std;

#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int d, s; cin >> d >> s;
    vec<int> mn(d), mx(d);
    int sum1 = 0, sum2 = 0;
    for (int i=0;i<d;i++) {
        cin >> mn[i] >> mx[i];
        sum1 += mn[i];
        sum2 += mx[i];
    }
    if (sum1>s || s>sum2) {cout << "NO\n";}
    else {
        cout << "YES\n";
        s -= sum1;
        for (int i=0;i<d;i++) {
            int e = min(mx[i]-mn[i],s);
            s -= e;
            cout << mn[i]+e << ' ';
        }
    }
}