#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    int books[n];
    for (int i=0;i<n;i++){
        cin >> books[i];
    }
    int ans = 0;
    int p1 = 0;
    int p2 = 0;
    int sum = 0;
    
    while (p1 < n && p2 < n) {
        while (p2 < n) {
            sum += books[p2++];
            if (sum > t) {
                sum -= books[--p2]; 
                break;
            }
        }
        ans = max(ans, p2-p1);
        sum -= books[p1++];
    }
    cout << ans << "\n";
}
