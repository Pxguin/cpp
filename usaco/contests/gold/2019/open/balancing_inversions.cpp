#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int n;
v<int> a;
ll ans = LLONG_MAX;
int d = 1; // d = 1, 10 pair = inversion; d = 0, 01 pair

void solve() {
    int l[2] = {0,0}, r[2] = {0,0};

    ll linv = 0, rinv = 0, moves = 0;
    int ptr = n;
    for (int i=n-1;i>=0;i--) { // calc # inversions and # 1's and # 0's in each half
        l[a[i]]++;
        if (a[i]==d) {linv += l[!d];}
    }
    for (int i=2*n-1;i>=n;i--) { 
        r[a[i]]++;
        if (a[i]==d) {rinv += r[!d];}
    }
    chmin(ans,abs(linv-rinv)); // initial answer
    int zeros = (d ? r[0] : 0);
    for (int i=n;i<2*n;i++) {
        if (a[i]) {
            while (ptr && a[ptr-1]) { // finding the latest 0 in the first half
                ptr--;
                if (d) {l[1]--;} // (casework)
            }
            if (ptr==0) {break;}
            moves += (n-ptr) + (i-n) + 1;
            if (d) { // if the inversion we're looking for is 10
                rinv -= zeros;
                linv -= l[1];
            } else { // if it's 01 (pretty much just casework to recalc # inversions in each half)
                r[1]--;
                rinv -= zeros; rinv += r[1];
                linv -= (n-ptr);
                zeros++;
                l[0]--;
                linv += l[0];
            }
            ptr--;
            chmin(ans,abs(linv-rinv)+moves); // update tot inversions
        } else { // can ignore; it's just the casework
            if (d) {zeros--;}
            else {zeros++;}
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("balance.in","r",stdin);
    freopen("balance.out","w",stdout);

    cin >> n;
    a.resize(2*n);
    F0R(i,2*n) {cin >> a[i];} 
    solve(); // right to left half
    d = 0;
    reverse(all(a)); // left to right half
    solve();
    cout << ans << '\n';
}