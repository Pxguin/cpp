#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define vec vector
 
void solve() {
    int n; cin >> n;
    vec<int> a(n);
    set<int> s = {-1,0};
    int mx = 0, mx2 = 0, ans = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        
        bool new_mx = false;
        if (a[i]>*s.rbegin()) {new_mx = true;}
        
        s.insert(a[i]);
        
        int mx = *s.rbegin(), mx2 = *prev(prev(s.end()));
            
        if (mx2>mx/2) {ans = mx;}
        else if (!new_mx) {
            chmax(ans,(a[i]%mx)+(mx%a[i]));
        } else { // everything is same except for the brute force
            for (auto it=prev(prev(s.end()));*it>mx2/2;it--) {chmax(ans,(*it) + mx%(*it));}
        } cout << ans << ' ';
    } cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    int t; cin >> t;
    while (t--) {solve();}
}