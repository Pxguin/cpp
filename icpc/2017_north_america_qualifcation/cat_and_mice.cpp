#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)

const int MAX_N = 16;
int x[MAX_N], y[MAX_N], t[MAX_N];
double dp[1<<MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    F0R(i,n) {cin >> x[i] >> y[i] >> t[i];}
    double m; cin >> m;

    x[n] = y[n] = t[n] = 0; // nth mouse is the starting position
    n++;

    double l = 0, h = 1e9, mid = (l+h)/2, ans = -1;
    F0R(z,40) { // binary search
        F0R(i,1<<n) F0R(j,n) {dp[i][j] = 1e9;} // reinit dp array
        dp[1<<(n-1)][n-1] = 0; // nth mouse is the starting position
        F0R(mask,1<<n) {
            double spd = mid*pow(m,__builtin_popcount(mask)-1); // get spd

            F0R(nxt,n) { // what mouse to eat next
                if (mask&(1<<nxt)) {continue;}
                F0R(last,n) { // which mouse was eaten last
                    if (!(mask&(1<<last))) {continue;}
                    double time = sqrt((x[last]-x[nxt])*(x[last]-x[nxt])+(y[last]-y[nxt])*(y[last]-y[nxt]))/spd;
                    if (time+dp[mask][last]<=t[nxt]) { // can we eat the next mouse in time
                        chmin(dp[mask|(1<<nxt)][nxt],time+dp[mask][last]); // yay
                    }
                }
            }
        }
        bool flag = false;
        F0R(i,n) {if (dp[(1<<n)-1][i]!=1e9) {flag = true;}} // if we can eat all mouse

        if (flag) {ans = mid; h = mid;}
        else {l = mid;}
        mid = (l+h)/2;
    }
    cout << fixed << setprecision(3) << ans << '\n';
}
