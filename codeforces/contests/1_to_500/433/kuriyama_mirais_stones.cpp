#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    ll a[n];
    ll ps1[n+1], ps2[n+1];
    for (int i=0;i<n;i++) {
        cin >> a[i];
        ps1[i+1] = a[i]+ps1[i];
    }
    sort(a, a+n);
    for (int i=0;i<n;i++) {ps2[i+1] = a[i]+ps2[i];}
    int m; cin >> m;
    while (m--) {
        int type, l, r; cin >> type >> l >> r;
        if (--type) {
            cout << ps2[r]-ps2[l-1];
        } else {cout << ps1[r]-ps1[l-1];}
        cout << "\n";
    }
}