#include <iostream>
using namespace std;
 
void solve() {
    int n; cin >> n;
    int b[n];
    int ps[n];
    int ss[n];
    for (int i=0;i<n;i++) {cin >> b[i];}
    ps[0] = b[0];
    ss[n-1] = b[n-1]-(n-1);
    for (int i=1;i<n;i++) {
        ps[i] = max(ps[i-1], b[i]+i);
    }
    for (int i=n-2;i>=0;i--) {
        ss[i] = max(ss[i+1], b[i]-i);
    }
 
    long long ans = 0;
    for (int i=1;i<n-1;i++) {
        ans = max(ans, (long long)b[i]+ps[i-1]+ss[i+1]);
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {solve();}
}