#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    char c;
    v<int> t(n), e(n);
    int lg, lh, fg=n,fh=n;
    F0R(i,n) {
        cin >> c;
        t[i] = (c=='G');
        if (c=='G') {lg = i; chmin(fg,i);} // find first and last cows of each breed
        else {lh = i; chmin(fh,i);}
    }
    v<int> cg(n+2,0), ch(n+2,0);
    F0R(i,n) { // difference arrays (# of cows of each breed with list going through each position)
        cin >> e[i];
        if (t[i]) {cg[e[i]+1]--; cg[i+1]++;}
        else {ch[e[i]+1]--; ch[i+1]++;}
        cg[i+1] += cg[i];
        ch[i+1] += ch[i];
    }
    int ans = 0;
    if (e[fh]>lh&&e[fg]>lg&&lg<fh||lh<fg) {ans++;} // both contain all cows of their breed
    if (e[fh]>lh) {ans += cg[fh+1];} // one breed contains other leader
    if (e[fg]>lg) {ans += ch[fg+1];} // other way around
    cout << ans << '\n';
}