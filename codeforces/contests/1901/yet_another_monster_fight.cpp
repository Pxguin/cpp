#include <iostream>
#include <climits>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int monsters[n];
    int ps[n];
    int ss[n];
    for (int i=0;i<n;i++) {
        cin >> monsters[i];
    }
    ps[0] = monsters[0]+(n-1);
    for (int i=1;i<n;i++){
        ps[i] = max(monsters[i]+(n-i-1), ps[i-1]);
    }
    ss[n-1] = monsters[n-1]+n-1;
    for (int i=n-2; i>=0; i--) {
        ss[i] = max(monsters[i]+i, ss[i+1]);
    }
 
    int ans = INT_MAX;
    int cur;
    
    for (int i=0;i<n;i++) {
        cur = monsters[i];
        if (i > 0) {cur = max(cur, ps[i-1]);}
        if (i < n-1) {cur = max(cur, ss[i+1]);}
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}