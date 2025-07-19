#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vec vector

int adj_inv[500001];

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vec<int> divs;
    for (int i=1;i*i<=m;i++) {
        if (m%i==0) {
            divs.pb(i); adj_inv[i] = 0;
            if (i*i!=m && m%(m/i)==0) {
                divs.pb(m/i); adj_inv[m/i] = 0;
            }
        }
    }
    vec<int> a(n);
    for (int i=0;i<n;i++) {cin >> a[i];}

    int d = divs.size();
    for (int i=0;i<d;i++) {
        for (int j=0;j<n;j++) { // precompute
            if (j) {
                adj_inv[divs[i]] += (a[j-1]%divs[i])>(a[j]%divs[i]);
            }
        }
    }

    while (q--) {
        int t; cin >> t;
        if (t==1) {
            int id, x; cin >> id >> x; id--;
            for (int i=0;i<d;i++) { // update
                adj_inv[divs[i]] -= (id && a[id-1]%divs[i]>a[id]%divs[i]);
                adj_inv[divs[i]] -= (id<n-1 && a[id]%divs[i]>a[id+1]%divs[i]);
                adj_inv[divs[i]] += (id && a[id-1]%divs[i]>x%divs[i]);
                adj_inv[divs[i]] += (id<n-1 && x%divs[i]>a[id+1]%divs[i]);
            } a[id] = x;
        } else {
            int k; cin >> k;
            int g = gcd(k,m);
            cout << (adj_inv[g]<m/g ? "YES" : "NO") << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}