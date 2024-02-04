#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k, n, w; cin >> k >> n >> w;
    int ans = 0;
    for (int i=1;i<w+1;i++) {ans += i*k;}
    cout << max(0, ans-n) << "\n";
}