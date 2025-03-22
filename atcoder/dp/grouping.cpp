#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX_N = 16;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    int a[MAX_N][MAX_N];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> a[i][j];
        }
    }
    ll cost[1<<MAX_N] = {0};
    for (int mask=1;mask<(1<<n);mask++) { // cost of each submask in n2^n
        for (int bit=0;bit<n;bit++) {
            if ((1<<bit)&mask) {
                cost[mask] = cost[mask^(1<<bit)];
                for (int bit2=bit+1;bit2<n;bit2++) {
                    if ((1<<bit2)&mask) {
                        cost[mask] += a[bit][bit2];
                    }
                }
                break;
            }
        }
    }

    ll dp[1<<MAX_N] = {0};
    for (int mask=1;mask<(1<<n);mask++) { // optimal cost for each grouping in 3^n
        for (int sm=mask;sm;sm=(sm-1)&mask) {
            dp[mask] = max(dp[mask],cost[sm]+dp[mask^sm]);
        }
    }
    cout << dp[(1<<n)-1] << '\n';
}