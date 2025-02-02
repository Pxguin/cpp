#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

const int MAX_N = 1e6, log2dist = 60;
int skip[MAX_N], skip2[MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll k, n, m; cin >> n >> k >> m;
    v<ll> p(n);
    F0R(i,n) {cin >> p[i];}

    int l = 0, r = k;
    F0R(i,n) {
        if (r<i) {l += i-r; r = i;}

        while (r<n-1 && l<i && p[r+1]-p[i]<p[i]-p[l]) {r++; l++;} // move sliding window while it decreases max dist
        skip[i] = ((p[r]-p[i]>p[i]-p[l] && r!=i)||(l==i) ? r : l); // is the left or right side max dist
    }
    int max_log = log2(m)+1;

    v<ll> ans(n);
    iota(all(ans),0);
    F0R(b,max_log) {
        if ((1LL<<b)&m) { // binary lifting
            F0R(i,n) {ans[i] = skip[ans[i]];}
        }
        F0R(i,n) { // update lift array
            skip2[i] = skip[skip[i]];
        }
        F0R(i,n) {skip[i] = skip2[i];}
    }
    F0R(i,n) {cout << ans[i]+1 << ' ';}
}