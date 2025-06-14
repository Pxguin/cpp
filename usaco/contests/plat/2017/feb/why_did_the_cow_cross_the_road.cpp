#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)
#define vec vector

const int MAX_N = 1e5+1;
struct BIT {
    int bit[MAX_N] = {0};
    void add(int i) {
        for (;i<=MAX_N;i+=i&-i) {bit[i]++;}
    }
    int sum(int i) {
        int res = 0;
        for (;i;i-=i&-i) {res += bit[i];}
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("mincross.in","r",stdin);
    freopen("mincross.out","w",stdout);
    
    int n; cin >> n;
    vec<int> a(n), b(n), to(n+1);
    for (int i=0;i<n;i++) {cin >> a[i];}
    for (int i=0;i<n;i++) {cin >> b[i];}

    ll ans = LLONG_MAX;
    for (int z=0;z<2;z++) { // fix the side that is being cycled
        BIT b1;
        ll cur = 0;
        for (int i=0;i<n;i++) {to[b[i]] = i+1;} // simplify indices
        for (int i=0;i<n;i++) { // amount of crossing pairs = number of inversions
            cur += i-b1.sum(to[a[i]]);
            b1.add(to[a[i]]);
        }
        chmin(ans,cur);
        for (int i=0;i<n;i++) { // try all cyclic shifts
            cur -= to[a[i]]-1;
            cur += n-to[a[i]];
            chmin(ans,cur);
        }
        swap(a,b);
    }
    cout << ans << '\n';
}