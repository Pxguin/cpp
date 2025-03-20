#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

const ll mod = 1e9+7;
void add2(ll& a, int b) {a = (a+b)%mod;}
int add(int a, int b) {return (a+b)%mod;}
int mul(ll a, ll b) {return a*b%mod;}

void solve() {
    int n; cin >> n;
    vec<int> ps(n+1,0), nxt(n+1,-1);
    F0R(i,n) {
        int a; cin >> a;
        ps[i+1] = ps[i]^a;
    }

    vec<vec<ll>> dp(n+1,vec<ll>(2,0));
    dp[0][0] = 1;

    map<int,int> last;
    for (int i=n;i>=0;i--) { // calculate next index with same prefix xor
        if (last.count(ps[i])) {
            nxt[i] = last[ps[i]];
        }
        last[ps[i]] = i;
    }

    F0R(i,n) { // transitions for dp[i][0] are always 3 times as much as dp[i][1]
        if (nxt[i]!=-1) {
            add2(dp[nxt[i]][0],mul(dp[i][0],3)); // because there's three valid starting moves for dp[i][0]
            add2(dp[nxt[i]][0],dp[i][1]); // but only one for dp[i][1]
            add2(dp[nxt[i]-(nxt[i]!=n)][1],mul(dp[i][1],2));
            add2(dp[nxt[i]-(nxt[i]!=n)][1],mul(dp[i][0],6));
        }
        if (nxt[i]==-1) { // this is a side case
            add2(dp[n][1],mul(dp[i][0],3));
            add2(dp[n][1],dp[i][1]);
        }
    }
    cout << add(dp[n][0],dp[n][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}