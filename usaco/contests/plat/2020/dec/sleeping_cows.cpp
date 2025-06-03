#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second

const int MAX_N = 3000;
int dp[2*MAX_N+1][MAX_N+1] = {0}, dp2[2*MAX_N+1][MAX_N+1] = {0};
pair<int,int> cow[2*MAX_N];

const int mod = 1e9+7;
void add(int& a, int b) {a = (a+b)%mod;}
ll mul(ll a, ll b) {return a*b%mod;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    for (int i=0;i<n;i++) {cin >> cow[i].f; cow[i].s = 0;}
    for (int i=0;i<n;i++) {cin >> cow[i+n].f; cow[i+n].s = 1;}
    sort(cow,cow+2*n);

    dp[0][0] = 1;
    pair<int,int> last = {-1,-1};
    for (int i=0;i<2*n;i++) { // calculate prefix dp for each cow
        for (int j=0;j<=n;j++) {
            if (cow[i].s==1) { // can choose whether to include barns or not,
                add(dp[i+1][j],dp[i][j]);
                if (j) {add(dp[i+1][j-1],mul(dp[i][j],j));}
            } else if (j!=n) { // but must take all cows
                add(dp[i+1][j+1],dp[i][j]);
            }
        }
    }
    for (int i=1;i<=2*n;i++) { // transition to suffix dp: try skipping each cow
        if (cow[i-1].s==0) {continue;}
        for (int j=0;j<=n;j++) {
            dp2[i][j] = dp[i-1][j];
        }
    }
    int ans = dp[2*n][0]; // dp[2*n][0]: amt perfect matchings 
    for (int i=1;i<2*n;i++) { // do the suffix dp
        for (int j=0;j<=n;j++) {
            if (cow[i].s==0) { // can choose to include cows,
                add(dp2[i+1][j],dp2[i][j]);
                if (j!=n) {add(dp2[i+1][j+1],dp2[i][j]);}
            } else if (j) { // but must take all barns
                add(dp2[i+1][j-1],mul(dp2[i][j],j));
            }
        }
    } add(ans,dp2[2*n][0]); // add the amount of not perfect matchings
    cout << ans << '\n';
}