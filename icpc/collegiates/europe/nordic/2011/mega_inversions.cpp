#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int a[n];
    F0R(i,n) {cin >> a[i];}

    vector<int> bit(n+1,0);
    auto add = [&](int idx) {
        for (;idx<=n;idx+=idx&-idx) {bit[idx]++;}
    };
    auto sum = [&](int idx) {
        int ret = 0;
        for (;idx>0;idx-=idx&-idx) {ret+=bit[idx];} 
        return ret;
    };
    int l[n];
    for (int i=n-1;i>=0;i--) {
        l[i] = sum(a[i]-1);
        add(a[i]);
    } F0R(i,n+1) {bit[i]=0;}
    ll ans = 0;
    F0R(i,n) {
        ans += (ll)(i-sum(a[i]))*l[i];
        add(a[i]);
    } cout << ans << '\n';
}   
