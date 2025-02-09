#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

const int MAX_N = 400000;
struct bit {
    ll b[MAX_N+1] = {0};
    void add(int i, ll a) {
        for (;i<=MAX_N;i+=i&-i) {b[i] += a;}
    }
    ll get(int i) {
        ll res = 0;
        for (;i>0;i-=i&-i) {res += b[i];if (i>MAX_N) {cout<<'e';}}
        return res;
    }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    bit sum, cnt;

    int n; cin >> n;
    v<pair<ll,int>> a(n);
    F0R(i,n) {cin >> a[i].f; a[i].s = i+1;}
    sort(all(a));

    ll ans = 0;
    F0R(i,n) {
        ans += (cnt.get(a[i].s)*a[i].f)-sum.get(a[i].s);
        sum.add(a[i].s,a[i].f);
        cnt.add(a[i].s,1);
    } cout << ans << '\n';
}