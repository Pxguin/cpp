#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, x; cin >> n;
    v<int> a(n); // pos array
    F0R(i,n) {
        cin >> x;
        a[--x] = i;
    }
    v<int> lis;
    F0R(i,n) {
        cin >> x;
        x = a[--x];
        int it = lower_bound(all(lis),x)-lis.begin();
        if (it==lis.size()) {lis.pb(x);}
        else {lis[it] = x;}
    } cout << lis.size() << '\n';
}