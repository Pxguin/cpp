#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<int> a(n);
    F0R(i,n) {cin >> a[i];}

    ll ans = 0, prev = 0;
    for (int c=25,p=(1<<25);c>=0;c--,p>>=1) {
        unordered_map<int,ll> mod, ctr;
        ll cur = 0;
        F0R(i,n) {
            int m = a[i]%p, pm = (p-m)%p;
            if (ctr.count(pm)) { // add amt of elements satisfying complementary mod
                cur += ctr[pm]*a[i]+mod[pm];
            }
            ctr[m]++; // update
            mod[m] += a[i];

        }
        ans += (cur-prev)/p;
        prev = cur;
    }
    F0R(i,n) {ans += a[i]/(a[i]&-a[i]);} // case for (i,i) (it's a_i divided by lsb of i)
    cout << ans << '\n';
}