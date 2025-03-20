#include <iostream>
#include <climits>
using namespace std;
 
void solve() {
    int n; cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    
    int cur = arr[0];
    int ans = arr[0];
    int mn = min(0, cur);
    
    for (int i=1;i<n;i++) {
        if (abs(arr[i])%2 == abs(arr[i-1])%2) {
            mn = 0; cur = 0;
        }
        cur += arr[i];
        ans = max(ans, cur-mn);
        mn = min(mn, cur);
    }
    cout << ans << "\n";
}
 
int main() {
    int t; cin >> t;
    while (t--) {solve();}
}