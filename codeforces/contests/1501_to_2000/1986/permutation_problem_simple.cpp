#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int MAX_N = 1e5;
v<int> divs[100001];

void solve() {
    int n; cin >> n;
    v<int> p(n),q(n);
    v<map<int,ll>> freq(n+1);

    ll ans = 0;
    F0R(i,n) {
        cin >> p[i];
        int g = gcd(p[i],i+1);
        q[i] = (i+1)/g; p[i] /= g;

        for (int d : divs[p[i]]) { // answer for q[i]
            ans += (freq[q[i]][d]);
        }

        for (int d : divs[p[i]]) {freq[d][q[i]]++;} // update array with p[i]
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    FOR(i,1,MAX_N+1) {
        for (int j=i;j<=MAX_N;j+=i) {divs[j].pb(i);}
    }
    int t; cin >> t;
    while (t--) {solve();}
}