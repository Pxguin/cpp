#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;
    v<pii> g(n);
    F0R(i,n) {cin >> g[i].f >> g[i].s;}
    sort(all(g),[&](pii& x, pii& y) {return (x.f-1)*y.s<(y.f-1)*x.s;}); // sort

    ll dp[11] = {0};
    dp[0] = 1;

    F0R(i,n) {
        for (int j=k-1;j>=0;j--) { // dp transition
            chmax(dp[j+1],(ll)g[i].f*dp[j]+g[i].s);
        }
    } cout << dp[k] << '\n';
}