#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("balancing.in","r",stdin);
    freopen("balancing.out","w",stdout);

    int n, b; cin >> n >> b;
    v<int> x(n), y(n);
    F0R(i,n) {cin >> x[i] >> y[i];}
    
    int ans = n;
    F0R(row,n) {
        F0R(col,n) {
            int xp = x[row]+1, yp = y[col]+1; // go through all rows/columns
            int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
            F0R(i,n) { // which quadrant is each cow in
                q1 += x[i]>xp && y[i]>yp;
                q2 += x[i]<xp && y[i]>yp;
                q3 += x[i]<xp && y[i]<yp;
                q4 += x[i]>xp && y[i]<yp;
            } chmin(ans,max({q1,q2,q3,q4})); // max of 4 quadrants
        }
    } cout << ans << '\n';
}