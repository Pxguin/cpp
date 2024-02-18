#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define MAX_N 200001
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, k, q; cin >> n >> k >> q;
    int events[MAX_N], ps[MAX_N];
    int l, r, cur=0;
    for (int i=0;i<n;i++) {
        cin >> l >> r;
        events[l]++; events[++r]--;
    }
    for (int i=1;i<=MAX_N;i++) {
        cur += events[i];
        ps[i] = ps[i-1]+(cur>=k);
    }
    while (q--) {
        cin >> l >> r;
        cout << ps[r]-ps[l-1] << "\n";
    }
}