#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector
 
void solve() {
    int n; cin >> n;
    vec<int> s(n), t(n);
    F0R(i,n) {char c; cin >> c; s[i] = (c=='1');}
    F0R(i,n) {char c; cin >> c; t[i] = (c=='1');}
    int ans = 1, one = 0, zero = 1;
    F0R(i,n) {
        if (s[i]!=t[i] && !one) { // if we need to change it, but there's no one
            if (s[i]==0) {ans = 0;} // case 1: this bit needs a one to change its state
            else {ans &= zero;} // if there's a non zero bit in this prefix of t, then it's impossible
        }
        one |= s[i]; // is there a one in s
        zero &= !t[i]; // is this current prefix of t all zeroes
    } cout << (ans ? "YES" : "NO") << '\n';
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    int t; cin >> t;
    while (t--) {solve();}
 
}