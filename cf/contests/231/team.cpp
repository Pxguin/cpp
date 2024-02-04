#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n; cin >> n;
    int ans = 0;
    for (int i=0;i<n;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ans += (a+b+c)/2;
    }
    cout << ans << "\n";
}