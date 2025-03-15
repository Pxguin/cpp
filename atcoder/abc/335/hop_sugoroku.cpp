#include <bits/stdc++.h>
using namespace std;

#define vec vector

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vec<int> a(n);

    const int s = sqrt(n-1);
    vec<int> dp(n,0); dp[0] = 1; // dp array
    vec<vec<int>> sum(s,vec<int>(s,0)); // prefix sum array
    int ans = 0;
    for (int i=0;i<n;i++) {
        int a; cin >> a;
        for (int j=1;j<s;j++) { // pull from states <= sqrt(n)
            dp[i] = (dp[i]+sum[j][i%j])%mod;
        }
            
        if (a>=s) { // then push to future states
            for (int j=i+a;j<n;j+=a) {
                dp[j] = (dp[j]+dp[i])%mod;
            }
        } else { // otherwise add to the prefix sum array
            sum[a][i%a] = (sum[a][i%a]+dp[i])%mod;
        }

        ans = (ans+dp[i])%mod;
    }
    cout << ans << '\n';
}#include <bits/stdc++.h>
using namespace std;

#define ll long long

void gcd(ll a, ll b, ll& x, ll& y) {
    if (b==0) {
        x = 1; y = 0;
        return;
    }
    ll x1, y1;
    gcd(b,a%b,x1,y1);
    x = y1;
    y = x1-y1*(a/b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll a, b; cin >> a >> b;

    ll a1 = abs(a), b1 = abs(b);
    ll g = gcd(a1,b1);
    if (g>2) {cout << "-1\n"; return 0;}

    ll x, y;
    gcd(a1,b1,x,y);
    if (g==1) {x *= 2; y *= 2;}
    if (a<0) {x = -x;}
    if (b>0) {y = -y;}
    cout << y << ' ' << x << '\n';

    /*
    |axb|=2
    (a,b); (c,d); ad-bc=2, or -2
    ad = 2+bc or ad=-2+bc
    a=0; (2a,0); same for b=0;

    a>0; b>0; 
    gcd(a,b)=1 or gcd(a,b)=2
    */
}