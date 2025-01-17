#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int mod = 1e9+7;
void add(ll& a, int b) {a = (a+b)%mod;}

ll dp[5001][101];
ll nxt[5001][101];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, x; cin >> n >> x;
    v<int> a(n);
    F0R(i,n) {cin >> a[i];}
    sort(all(a));

    dp[0][1] = 1;
    dp[0][0] = 1;

    F0R(i,n-1) {
        ll d = a[i+1]-a[i];
        F0R(j,x+1) {
            F0R(k,n+1) {
                if (dp[j][k] && j+d*k<=x) {
                    nxt[j+d*k][k] += dp[j][k]*k; // dont change number of teams
                    
                    if (k<n-1) {
                        nxt[j+d*k][k+1] += dp[j][k]; // add new team
                        nxt[j+d*k][k] += dp[j][k]; // start and end one team
                    }
                    if (k>0) {
                        nxt[j+d*k][k-1] += dp[j][k]*k; // end one team
                    }
                }
            }
        }
        F0R(j,x+1) {
            F0R(k,n+1) {
                dp[j][k] = nxt[j][k]%mod;
                nxt[j][k] = 0;
            }
        }
    }
    ll ans = 0;
    F0R(i,x+1) {add(ans,dp[i][0]);}
    cout << ans << '\n';
}