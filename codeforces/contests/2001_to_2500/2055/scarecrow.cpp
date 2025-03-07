#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n, k, l; cin >> n >> k >> l;
    k*=2; l*=2;
    v<int> a(n);
    F0R(i,n) {
        cin >> a[i]; a[i]*=2;
    }

    int t = a[0];
    int x = k;
    int ans = t+max(0,l-x);

    for (int i=1;i<n;i++) {
        int p = a[i];
        if (p>=x && x>=p-t) {x = x+k;} // case 1: the crow can teleport instantly again
        else if (x<p-t) { // case 2: move scarecrow until crow is ahead of it
            int t2 = t;
            t += (p-t2-x)/2;
            x = (p-t2+x)/2+k;
        } else { // case 3: move scarecrow as far right as possible to meet the crow
            x = min(p+t,x)+k;
        }
        chmin(ans,t+max(0,l-x));
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}