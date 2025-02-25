#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

void solve() {
    int n, m; cin >> n >> m;
    v<int> a(n), b(m);
    F0R(i,n) {cin >> a[i];}
    F0R(i,m) {cin >> b[i];}
    sort(all(a)); sort(all(b));

    v<ll> ans;
    v<ll> pair_n(n/2+1,0), pair_m(m/2+1,0);
    F0R(i,n/2) {
        pair_n[i+1] = pair_n[i]+(a[n-i-1]-a[i]);
    }
    F0R(i,m/2) {
        pair_m[i+1] = pair_m[i]+(b[m-i-1]-b[i]);
    }

    auto check = [&](int x, int k) {
        return pair_n[x]+pair_m[k-x];
    };

    while (true) { // continue while possible
        int k = ans.size()+1;
        int l = max(0,max(k-m/2,2*k-m))-1, h = min(n-k,min(k,n/2)); // upper/lower bound x given k

        if (l+1>h) {break;} // break when impossible

        while (h-l>1) { // ternary search on maximum
            int mid = (l+h)>>1;
            if (check(mid,k)>check(mid+1,k)) {
                h = mid;
            } else {l = mid;}
        }
        ans.pb(check(l+1,k)); // l+1 is the max
    }
    cout << ans.size() << '\n';
    for (ll x : ans) {cout << x << ' ';}
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}