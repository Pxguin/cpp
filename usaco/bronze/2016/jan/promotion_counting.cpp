#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("promote.in","r",stdin);
    freopen("promote.out","w",stdout);

    int b[4], a[4];
    F0R(i,4) {cin >> b[i] >> a[i];}

    int c = 0;
    F0R(i,4) {c += a[i];}
    F0R(i,4) {c -= b[i];} // initialize ctr to # of new participants in contest
    
    F0R(i,3) {
        c += b[i]-a[i]; // add "before", subtract "after"
        cout << c << '\n';
    }
}