#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmax(a, b) a = max(a,b)

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    ll ans = 1;
    if (n==1 && s[0]=='0') {ans = 0;}
    
    ll last = -2, last_down = 0; // stores last '0' and area of bottom half of that component
    for (int i=0;i<n;i++) {
        if (s[i]=='1') {continue;}
        int ptr = i;
        while (ptr<n && s[ptr]=='0') {ptr++;} // find a connected component of all zeroes
        ll up = (ll)(ptr-1+i)*(ptr-i)/2; // when extending to 2d, store the area of the top half
        ll down = (ll)(n-1)*(ptr-i)-up; // and bottom half of that component

        if (i!=0) {up++;}
        if (last==i-1) {up += last_down;} // can it connect to previous component

        last = i = ptr;
        last_down = down;
        if (ptr!=n) {down++;}
        chmax(ans,max(up,down));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}