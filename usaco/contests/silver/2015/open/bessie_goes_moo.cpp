#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("bgm.in","r",stdin);
    freopen("bgm.out","w",stdout);

    int n; cin >> n;
    char var[7] = {'B','E','S','I','G','O','M'};
    int to[26];
    F0R(i,7) {to[var[i]-'A'] = i;}

    v<v<int>> freq(7,v<int>(7,0));
    F0R(i,n) {
        char c; int val; cin >> c >> val;
        freq[to[c-'A']][(val%7+7)%7]++;
    }
    ll ans = 0;
    F0R(b,7) { F0R(e,7) { F0R(s,7) { F0R(i,7) {F0R(g,7) { F0R(o,7) { F0R(m,7) { // try all possible combinations
        if ((b+e+s+s+i+e)%7==0 || (g+o+e+s)%7==0 || (m+o+o)%7==0) { // does it work
            ans += (ll)freq[0][b]*freq[1][e]*freq[2][s]*freq[3][i]*freq[4][g]*freq[5][o]*freq[6][m];
        }
    }}}}}}}
    cout << ans <<'\n';
}