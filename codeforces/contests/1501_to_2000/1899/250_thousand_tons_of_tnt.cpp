#include <iostream>
#include <climits>
using namespace std;
 
void solve() {
    int n; cin >> n;
    long box[n];
    for (int i=0;i<n;i++) {
        cin >> box[i];
    }
    long long ans = 0;
    long long max_t, min_t;
    for (int i=1;i<=n;i++) {
        if (n%i==0) {
            max_t = 0; min_t = LLONG_MAX;
            for (int j=0;j<n;j+=i) {
                long long total = 0;
                for (int k=j;k<j+i;k++) {
                    total += box[k];
                }
                max_t = max(total,max_t);
                min_t = min(total, min_t);
            }
            ans = max(max_t-min_t, ans);
        }
    }
    cout << ans << "\n";
}
 
int main() {
    int t; cin >> t;
    while (t--) {solve();}
}
