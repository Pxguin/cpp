#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;

    v<v<pii>> lex(n+1,v<pii>(n+1,{0,0}));

    for (int i=n-1;i>=0;i--) { // comparing lex min strings
        for (int j=n-1;j>=0;j--) {
            if (i==n-2&&j==n-2) {continue;}
            if (s[i]<s[j]) {lex[i][j] = {1,0};}
            else if (s[i]>s[j]) {lex[i][j] = {1,1};}
            else {lex[i][j] = lex[i+1][j+1]; lex[i][j].f++;}
        }
    }
    auto cmp = [&](int s1, int s2, int len) {
        if (lex[s1][s2].f>len) {return true;}
        return (!lex[s1][s2].s);
    };

    v<int> ans(n+1,0);
    FOR(L,1,n+1) {
        v<int> left(n), right(n);
        F0R(i,n-L+1) {
            left[i] = right[i] = i;
            for (int j=i-1;j>=0;j--) { // finding l_i and r_i
                if (!cmp(j,i,L)) {left[i]=j=left[j];}
                else {break;}
            }
        }
        for (int i=n-L;i>=0;i--) {
            FOR(j,i+1,n-L+1) {
                if (cmp(i,j,L)) {right[i]=j=right[j];}
                else {break;}
            }
        }
        v<int> ps(n+2,0);
		F0R(i,n-L+1) { // update ranges with difference arrays
			ps[L]++;
			ps[i-left[i]+right[i]-i+L+1]--;
		}
        FOR(K,L,n+1) { // sum up ranges, ps[K] = value for this (K,L) pair
            ps[K] += ps[K-1];
            ans[ps[K]]++;
        }
    }
    FOR(i,1,n+1) {cout << ans[i] << '\n';}
}