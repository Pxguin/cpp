#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define s second
#define f first

/* 
dp[i][j]: after the jth turn, if the jth player could have had the ball
dp[i][j] = dp[i-1][j+-dist]
*/

bool dp[1001][1001];

void solve() {
    int n, m, x; cin >> n >> m >> x;
    dp[0][x] = true;
    
    for (int i=1;i<=m;i++) {
        int dist; char dir; cin >> dist >> dir;
        for (int j=1;j<=n;j++) {
            dp[i][j] = 0;
            if (dir == '?' || dir == '0') {
                dp[i][j] = dp[i][j] || dp[i-1][(n+j-dist-1)%n+1];
            }
            if (dir == '?' || dir == '1') {
                dp[i][j] = dp[i][j] || dp[i-1][(j+dist-1)%n+1];
            }
        }
    }
    queue<int> ans;
    for (int i=1;i<=n;i++) {
        if (dp[m][i]) {ans.push(i);}
    }
    cout << ans.size() << '\n';
    while (ans.size()) {cout << ans.front() << ' '; ans.pop();} cout << '\n';
    dp[0][x] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while (t--) {solve();}
}
