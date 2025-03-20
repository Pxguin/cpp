#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define ld long double
 
void solve() {
    int n; cin >> n;
    ld a[n];
    ld prev = 0;
    ld cur = 0;
    ll ans = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=1;i<n;i++) {
        if (a[i] <= a[i-1]) {
            cur = ceil(log2(a[i-1]/a[i])+prev);
        } else {
            cur = max((ld)0, ceil(prev-log2(a[i]/a[i-1])));
        }
        ans += cur;
        prev = cur;
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while (t--) {solve();}
}