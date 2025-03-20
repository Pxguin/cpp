#include <iostream>
#include <algorithm>
using namespace std;
 
void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int s[m]; for (int i=0;i<m;i++) {cin >> s[i];}
    int tm; int run;
    if (b>a) {tm = b-a; run = a-1;}
    else {tm = a-b; run = n-a;}
    sort(s, s+m);
    
    int l = 0; int h = tm-2; if (h>=m) {h = m-1;}
    int cur = (l+h)/2;
    int ans = 0; 
    int lw = 0;
    
    while (l <= h) {
        bool works = true;
        for (int i=cur;i>=0;i--) {
            if (s[i]+(cur-i+1) > tm+run) {
                works = false; break;
            }
        }
        if (works) {
            ans = cur+1;
            l = cur+1;
        } else {
            h = cur-1;
        }
        cur = (l+h)/2;
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {solve();}
}