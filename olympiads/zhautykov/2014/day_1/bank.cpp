#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)

const int MAX_N = 20;
int a[MAX_N], b[MAX_N], ps[MAX_N+2] = {0};
int dp[1<<MAX_N] = {0};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    F0R(i,n) {cin >> a[i]; ps[i+1] = a[i]+ps[i];}
    F0R(i,m) {cin >> b[i];}
    
    int ans = 0;
    F0R(mask,1<<m) {
        chmax(ans,dp[mask]);
        int sum = 0;
        F0R(j,m) { // sum of all bills
            if ((1<<j)&mask) {sum += b[j];}
        }
        F0R(j,m) {
            if (!((1<<j)&mask)) { // add to subset and see if we can pay off the next person
                chmax(dp[mask|(1<<j)],dp[mask]+(sum+b[j]==ps[dp[mask]+1]));
            }
        }
    }
    cout << (ans==n ? "YES" : "NO") << '\n';
}
