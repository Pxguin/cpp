#include <bits/stdc++.h>
using namespace std;

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
    F0R(i,n) {cin >> a[i].s >> a[i].f;}
    sort(all(a)); // sort by ending time

    int last = -1, ans = 0;
    F0R(i,n) {
        if (a[i].s>=last) {last = a[i].f; ans++;}
    } cout << ans << '\n';
}