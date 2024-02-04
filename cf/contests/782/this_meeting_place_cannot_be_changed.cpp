#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;
 
#define ld long double
 
int n;
vector<int> spd; vector<int> dist;
 
bool check(ld t) {
    ld low_bound = 0;
    ld high_bound = INT_MAX;

    for (int i=0;i<n;i++) {
        ld low = dist[i]-((ld)spd[i]*t);
        ld high = dist[i]+((ld)spd[i]*t);
        low_bound = max(low_bound, low);
        high_bound = min(high_bound, high);
    }
    return (low_bound <= high_bound);
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    spd.resize(n);
    dist.resize(n);
 
    for (int& i:dist) {cin >> i;}
    for (int& i:spd) {cin >> i;}
 
    ld l = 0;
    ld h = 1000000000;
    ld m = (l+h)/2;
    ld ans = 0;
 
    for (int i=0;i<100;i++) {
        if (check(m)) {
            h = m;
            ans = m;
        } else {l = m;}
        m = (l+h)/2;
 
    }
 
    cout << fixed << setprecision(12) << ans << "\n";
}