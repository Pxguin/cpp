#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define chmin(a, b) a = min(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 5000, MAX_C = 1435, P = 25;
vec<int> good, primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

ll dp[MAX_N][MAX_C], a[MAX_N], prime[MAX_N][P];
vec<int> adj[MAX_N], divs[MAX_C];

bool test(int x) { // either <= 100; or square free & all prime factors are <= 100
    if (x<=100) {return true;}
    for (int p : primes) {
        if (x%p==0) {x /= p;}
    } return x==1;
}

void pre() {
    for (int i=1;i<2*MAX_N;i++) {if (test(i)) {good.pb(i);}}
    for (int i=0;i<MAX_C;i++) {for (int j=0;j<P;j++) { // also precalc prime divisors of all good number
        if (good[i]%primes[j]==0) {divs[i].pb(j);}
    }}
}

void dfs(int cur) {
    for (int x : adj[cur]) { // calculate for children
        adj[x].erase(find(all(adj[x]),cur));
        dfs(x);
    }
    for (int i=0;i<MAX_C;i++) { // fix the value of this node
        ll sum = (a[cur]==i+1 ? 0 : good[i]); // cost to change it
        for (int x : adj[cur]) {
            ll add = 1e10;
            for (int j : divs[i]) {chmin(add,prime[x][j]);} // min cost to change the child to something gcd harmonic w/ this node
            sum += add;
        } chmin(dp[cur][i],sum);

        for (int j : divs[i]) {chmin(prime[cur][j],dp[cur][i]);} // update transition array
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    pre();

    int n; cin >> n;
    for (int i=0;i<n;i++) {cin >> a[i];}
    for (int i=0;i<n-1;i++) {
        int c, d; cin >> c >> d;
        adj[--c].pb(--d); adj[d].pb(c);
    }
    for (int i=0;i<n;i++) {for (int j=0;j<MAX_C;j++) {dp[i][j] = 1e10;}} // base case
    for (int i=0;i<n;i++) {for (int j=0;j<P;j++) {prime[i][j] = 1e10;}}
    dfs(0);

    ll ans = LLONG_MAX; // answer
    for (int i=0;i<MAX_C;i++) {chmin(ans,dp[0][i]);}
    cout << ans << '\n';
}