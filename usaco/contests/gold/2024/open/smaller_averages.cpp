#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int mod = 1e9+7;

bool ok(pii& a, pii& b) {return (a.f*b.s)<=(b.f*a.s);} // compare two fractions
bool cmp(pair<pii,int>& a, pair<pii,int>& b) {return (a.f.f*b.f.s)<(b.f.f*a.f.s);} // modified version for sorting
void add(int& a, int b) {a = (a+b)%mod;}
void sub(int& a, int b) {a = (a-b+mod)%mod;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<int> a(n), b(n);
    F0R(i,n) {cin >> a[i];}
    F0R(i,n) {cin >> b[i];}

    v<v<pair<pii,int>>> avg_b1(n), avg_a2(n); // b1[i]: sort all averages [j,i]; a2[i]: sort all averages [i,j]
    v<v<int>> dp(n,v<int>(n,0));
    v<pii> sum(n);
    F0R(i,n) {
        ll s1=0, s2=0, s3=0;
        for (int j=i;j>=1;j--) { // calculating the arrays
            s1 += a[j]; s2 += b[j];
            avg_b1[i].pb({{s2,i-j+1},j-1});
        }
        sum[i] = {s1+a[0],s2+b[0]};
        for (int j=i+1;j<n;j++) {
            s3 += a[j];
            avg_a2[i].pb({{s3,j-i},j});
        }
        sort(all(avg_a2[i]),cmp);
        sort(all(avg_b1[i]),cmp);
    }

    F0R(i,n) {
        F0R(j,n) {
            add(dp[i][j],(sum[i].f*(j+1))<=(sum[j].s*(i+1))); // base case
            
            int tota = 0, ptra = 0;
            for (pair<pii,int>& x : avg_b1[j]) {add(tota,dp[i][x.s]);} // 2 pointers
            for (pair<pii,int>& x : avg_a2[i]) { // pull from B ranges, push to A ranges
                while (ptra<avg_b1[j].size() && !ok(x.f,avg_b1[j][ptra].f)) {sub(tota,dp[i][avg_b1[j][ptra++].s]);}
                add(dp[x.s][j],tota);
            }
        }
    }
    cout << dp[n-1][n-1] << '\n';
}