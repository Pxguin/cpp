#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int solve() {
    int a, b, c, m; cin >> a >> b >> c >> m;
    
    vector<int> usb; vector<int> ps2;
    int val; string port;
    for (int i=0;i<m;i++) {
        cin >> val >> port;
        if (port == "USB") {usb.push_back(val);}
        else {ps2.push_back(val);}
    }
    sort(usb.begin(),usb.end());
    sort(ps2.begin(),ps2.end());
    int ans = 0; long long cost = 0;
    
    int p1 = 0; // usb 
    int p2 = 0; // ps2
    while (p1 < usb.size() && a > 0) {
        cost += usb[p1];
        ans++; a--; p1++;
    }
    while (p2 < ps2.size() && b > 0) {
        cost += ps2[p2];
        ans++; b--; p2++;
    }
    while ((p1 < usb.size() || p2 < ps2.size()) && c > 0) {
        if (p1 >= usb.size()) {
            cost += ps2[p2];
            p2++;
        } else if (p2 >= ps2.size()) {
            cost += usb[p1];
            p1++;
        } else {
            if (usb[p1] < ps2[p2]) {
                cost += usb[p1]; p1++;
            } else if (ps2[p2] <= usb[p1]) {
                cost += ps2[p2]; p2++;
            }
        }
        ans++; c--;
    }
    cout << ans << " " << cost << "\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}