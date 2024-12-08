#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<pii> a(n);
    F0R(i,n) {cin >> a[i].f >> a[i].s;}
    sort(all(a));

    ll sum = 0, ans = 0;
    F0R(i,n) {
        sum += a[i].f;
        ans += a[i].s-sum;
    } cout << ans << '\n';
}