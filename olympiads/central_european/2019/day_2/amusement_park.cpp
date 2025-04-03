#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX_N = 18, mod = 998244353, inv = 499122177;
map<int,int> dp[1<<18];
int adj[MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a] |= (1<<b);
        adj[b] |= (1<<a);
    }

    dp[0][(1<<n)-1] = 1;

    for (int mask=0;mask<(1<<MAX_N);mask++) {
        for (auto[cand,x] : dp[mask]) {
            for (int j=0;j<n;j++) {
                if (!(cand&(1<<j))) {continue;}

                int remove_bad = ((1<<n)-1)^((1<<(j+1))-1);
                int remove_used = ((1<<n)-1)^mask;

                int cand2 = (cand&remove_bad)|(adj[j]&remove_used);
                dp[mask|(1<<j)][cand2] = (dp[mask|(1<<j)][cand2] + x)%mod;
            }
        }
    }
    cout << (ll)m*dp[(1<<n)-1][0] %mod *inv %mod << '\n';
}
