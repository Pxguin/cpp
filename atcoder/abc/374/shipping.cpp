#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)

const int MAX_N = 100;
ll dp[MAX_N+1][MAX_N+2];
ll t[MAX_N+1];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n, k, x; cin >> n >> k >> x;
    F0R(i,n) {cin >> t[i];}
    t[n] = 1e18; // dummy shipment
    F0R(i,n+1) {
        F0R(j,n+1) {
            dp[i][j] = LLONG_MAX;
        }
    }
    dp[0][1] = 0;
    F0R(i,n) {
        F0R(j,n+1) {
            if (dp[i][j]==LLONG_MAX) {continue;}
            ll time = t[i], cost = dp[i][j];
            ll ptr = i+1, rem = j;
            chmin(dp[i+1][j+1],dp[i][j]+(t[i+1]-t[i])*rem);
            while (rem!=0) { // make this many continuous shipments
                rem -= min(k,rem); // make a shipment
                cost += x*rem;
                time += x;
                while (t[ptr]<time) { // add in the shipments that arrive during the waiting period of X
                    rem++;
                    cost += time-t[ptr++];
                }
                chmin(dp[ptr][rem+1],cost+(t[ptr]-time)*rem); // ptr is the first shipment that can be shipped at time t_ptr
            }
        }
    } cout << dp[n][1] << '\n';
}