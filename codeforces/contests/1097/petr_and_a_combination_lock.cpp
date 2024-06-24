#include <iostream>
#include <vector>
using namespace std;
 
int n; vector<int> a;
 
void solve() {
    for (int mask=0;mask<(1<<n);mask++) {
        int cur = 0;
        for (int i=0;i<n;i++) {
            cur += (mask&(1<<i)) ? a[i] : -a[i];
        }
        
        if (abs(cur)%360 == 0) {
            cout << "YES"; return;
        }
    }
    cout << "NO";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int i=0;i<n;i++) {cin >> a[i];}
    solve();
}