#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<v<int>> a(n+1);
    F0R(i,n) {
        int a1; cin >> a1;
        a[a1].pb(i);
    }
    ll ans = 0;
    for (int i=1;i<=n;i++) {
        int prev = 0;
        for (int x : a[i]) { // find bounds such that we select L=x
            int l = lower_bound(all(a[i-1]),x)-a[i-1].begin()-1;
            l = max(prev,(l==-1 ? 0 : a[i-1][l]+1)); // find leftmost bound

            int r = upper_bound(all(a[i-1]),x)-a[i-1].begin();
            r = (r==a[i-1].size() ? n-1 : a[i-1][r]-1); // find rightmost bound

            ans += (ll)(x-l+1)*(r-x+1);
            prev = x+1;
        }
    } cout << ans << '\n';
}