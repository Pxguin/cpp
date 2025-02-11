#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)

int a[500005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    ll ans = 0;
    F0R(i,n) {
        cin >> a[i];
        ans += upper_bound(a,a+i,a[i]/2)-a; // count number of mochi <= a[i]/2
    } cout << ans << '\n';
}