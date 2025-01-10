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

    int n, x; cin >> n >> x;
    v<pii> a(n);
    F0R(i,n) {
        cin >> a[i].f;
        a[i].s = i;
    } sort(all(a));

    int p1 = 0, p2 = n-1;
    int a1 = -1, a2 = -1;

    while (p1 < p2) {
        if (a[p1].f+a[p2].f<x) {p1++;} // is sum less than x
        else if (a[p1].f+a[p2].f>x) {p2--;} // is sum greater than x
        else { // we have found our values
            a1 = a[p1].s; a2 = a[p2].s;
            break;
        }
    }
    if (a1==-1) {cout << "IMPOSSIBLE";}
    else {cout << a1+1 << ' ' << a2+1;}
}