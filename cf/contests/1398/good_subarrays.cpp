#include <iostream>
#include <map>
using namespace std;
 
void solve() {
    int n; cin >> n;
    map<int, int> ps;
    int sum = 0;
    ps[1] = 1;
    char a;
    long long ans = 0;
    for (int i=0;i<n;i++) {
        cin >> a; 
        sum += (a-'0');
        if (ps.count(sum-i)) {
            ps[sum-i]++;
        } else {ps[sum-i] = 1;}
        ans += ps[sum-i]-1;
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {solve();}
}