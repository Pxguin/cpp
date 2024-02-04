#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;
 
int n;
double temp[3];
 
bool search(int& d, vector<int>& x) {
    bool works = false;
 
    int p1 = 0;
    for (int i=0;i<3;i++) {
        int p2 = upper_bound(x.begin(), x.end(), x[p1]+d)-x.begin()-1;
        if (p2 == n-1) {
            works = true;
            for (int j=i;j<3;j++) {
                temp[j] = x[p1]+(d/2.0);
            }
            break;
        }
        temp[i] = x[p1]+(d/2.0);
        p1 = p2+1;
    }
    return works;
}
 
void solve() {
    cin >> n;
    vector<int> x(n);
    for (int i=0;i<n;i++) {
        cin >> x[i];
    } sort(x.begin(), x.end());
    int dist = x[n-1]-x[0];
    int l = 0; int h = dist; int d = (l+h)/2;
 
    double ans = INT_MAX;
    double loc[3];
    while (l <= h) {
        if (search(d, x)) {
            h = d-1;
            ans = d/2.0;
            for (int i=0;i<3;i++) {
                loc[i] = temp[i];
            }
        } else {
            l = d+1;
        }
        d = (l+h)/2;
    }
    cout << fixed; cout << setprecision(6);
    cout << ans << "\n";
    for (double i : loc) {
        cout << i << " ";
    }
 
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}