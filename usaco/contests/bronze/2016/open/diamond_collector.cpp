#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    
    int n, k; cin >> n >> k;
    v<int> a(n);
    F0R(i,n) {cin >> a[i];}
    sort(all(a));
    int ans = 0;
    F0R(i,n) { // left endpoint
        int j = i+1;
        for (;j<n&&(a[j]-a[i]<=k);j++) {} // iterate right endpoint while possible
        chmax(ans,j-i);
    } cout << ans << '\n';
}