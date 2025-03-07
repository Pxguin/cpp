#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    string s; cin >> s;
    int n = s.size(), q; cin >> q;

    v<v<int>> pal(n,v<int>(n,0));
    F0R(i,n) {pal[i][i] = 1;}
    F0R(i,n-1) {pal[i][i+1] = (s[i]==s[i+1]);}

    FOR(sz,2,n) { // calc if each range is a palindrome
        F0R(i,n-sz) {
            int j = i+sz;
            pal[i][j] = (s[i]==s[j])&&(pal[i+1][j-1]);
        }
    }
    FOR(sz,1,n) { // dp to sum up ranges
        F0R(i,n-sz) {
            int j = i+sz;
            pal[i][j] += (pal[i+1][j]+pal[i][j-1]-pal[i+1][j-1]);
        }
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << pal[--l][--r] << '\n';
    }
}