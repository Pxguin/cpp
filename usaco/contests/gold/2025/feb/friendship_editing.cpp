#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)

const int MAX_N = 16;
bool adj[MAX_N][MAX_N] = {false};
int cost[1<<MAX_N] = {0}, dp[1<<MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        adj[--a][--b] = true;
        adj[b][a] = true;
    }
    for (int mask=0;mask<(1<<n);mask++) { // cost of creating the component specified by mask
        for (int i=0;i<n;i++) {
            if (!((1<<i)&mask)) {continue;}
            for (int j=0;j<i;j++) {
                if ((1<<j)&mask) {
                    cost[mask] += adj[i][j];
                } else {
                    cost[mask] += !adj[i][j];
                }
            }
        }
    }
    fill(dp,dp+(1<<n),INT_MAX);
    dp[0] = 0;
    for (int mask=0;mask<(1<<n);mask++) { // add components bitmask dp
        int comp = ((1<<n)-1)^mask;
        for (int add=comp;add;add=(add-1)&comp) {chmin(dp[mask|add],dp[mask]+cost[add]);}
    } cout << dp[(1<<n)-1] << '\n';
}