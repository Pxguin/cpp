#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define vec vector

vec<ll> p, p2, a, a2;
ll ub = 1e18;
void dfs(ll cur, ll id) {
    a.pb(cur);
    for (int x=id;x<p.size();x++) {
        if (cur<=ub/p[x]) {dfs(cur*p[x],x);}
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    p.resize(n/2); p2.resize((n+1)/2);
    for (int i=0;i<n/2;i++) {cin >> p[i];}
    for (int i=0;i<(n+1)/2;i++) {cin >> p2[i];}
    dfs(1,0); swap(a,a2); swap(p,p2); dfs(1,0);

    sort(all(a)); sort(all(a2));

    ll k; cin >> k;
    ll lo = 1, hi = ub, mid = (lo+hi)/2, ans = 0;
    while (lo<=hi) { // bin search on answer
        ll cnt = 0;
        for (int p1=0,p2=a2.size()-1;p1<a.size();p1++) { // 2p to get amount <= mid
            while (p2>=0 && a2[p2]>mid/a[p1]) {p2--;}
            cnt += p2+1;
        }
        if (cnt>=k) {hi = mid-1; ans = mid;}
        else {lo = mid+1;}
        mid = (lo+hi)/2;
    } cout << ans << '\n';
}