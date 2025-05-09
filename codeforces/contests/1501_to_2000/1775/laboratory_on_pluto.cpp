#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX_N = 4e5, MAX_W = 733;
int mod;

int perim[MAX_N+1], dp[4][MAX_W+1];
int u;

void add(int& a, int b) {a = ((a+b)%mod+mod)%mod;}
int mul(ll a, ll b) {return a*b%mod;}

void calc() {
    for (int i=1,sq=1;i<=MAX_N;i++) {
        if ((sq+1)*(sq+1)==i) {sq++;}
        perim[i] = 4*sq+2*((i>sq*sq)+(i>sq*sq+sq));
        perim[i] /= 2;
    }
    if (u==2) {
        // do the dp
        dp[0][0] = 1;
        
        for (int i=1;i<=MAX_W;i++) {
            int b = 1, m = 1;

            while (b*(3*b-1)/2<=i) {
                add(dp[0][i],m*dp[0][i-b*(3*b-1)/2]);
                if (b<0) {b--; m *= -1;}
                b *= -1;
            }
        }
        for (int t=0;t<3;t++) {
            for (int i=0;i<=MAX_W;i++) {
                for (int j=0;j<=MAX_W-i;j++) {
                    add(dp[t+1][i+j],mul(dp[t][i],dp[0][j]));
                }
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    if (u==1) {
        int w = sqrt(n), h = n/w;
        cout << (n+w-1)/w << ' ' << w << '\n';
        for (int i=0;i<h;i++) {
            for (int j=0;j<w;j++) {cout << '#';}
            cout << '\n';
        }
        if (h*w!=n) {
            for (int i=0;i<n%w;i++) {cout << '#';}
            for (int i=n%w;i<w;i++) {cout << '.';}
            cout << '\n';
        }
    } else {
        int ans = 0;
        for (int w=1;w<=MAX_W;w++) {
            if (w*(perim[n]-w)>=n) {
                add(ans,dp[3][w*(perim[n]-w)-n]);
            }
        }
        cout << 2*perim[n] << ' ' << ans << '\n'; 
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t >> u;
    if (u==2) {cin >> mod;}
    calc();

    while (t--) {solve();}
}