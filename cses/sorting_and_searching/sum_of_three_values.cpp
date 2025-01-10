#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
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
    } 
    
    sort(all(a));

    int a1 = -1, a2, a3;
    F0R(i,n-2) {
        int p = n-1;
        FOR(j,i+1,n-1) { // iterate second ptr forward
            if (p<=j) {break;}
            while (p>j+1 && a[i].f+a[j].f+a[p].f>x) {p--;} // iterate third ptr backwards
            
            if (a[i].f+a[j].f+a[p].f==x) {
                a1 = a[i].s; a2 = a[j].s; a3 = a[p].s;
            }
        }
    }

    if (a1==-1) {cout << "IMPOSSIBLE";}
    else {cout << a1+1 << ' ' << a2+1 << ' ' << a3+1;}
}