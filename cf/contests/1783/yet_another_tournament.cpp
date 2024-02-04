#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
void solve() {
    int n, m; cin >> n >> m;
    int a[n]; int sorted[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }
    sort(sorted, sorted+n);
    int sum = 0;
    int mx = 0;
    for (int i=0;i<n;i++) {
        if (sum+sorted[i] > m) {
            break;
        } sum += sorted[i]; mx++;
    }
    if (mx != 0 && mx != n && sum-sorted[mx-1]+a[mx] <= m) {mx++;}
    cout << n+1-mx << "\n";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {solve();}
}