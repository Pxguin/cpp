#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector
 
void solve() {
    int n, m; cin >> n >> m;
    vec<vec<int>> a(n,vec<int>(m));
    F0R(i,n) {
        F0R(j,m) {
            cin >> a[i][j];
        }
    }
    if (n==1 && m==1) {cout << "-1\n"; return;}
    F0R(i,n) {
        F0R(j,m) {
            cout << (a[i][j])%(n*m)+1 << ' '; // cycle each by one
        } cout << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    int t; cin >> t;
    while (t--) {solve();}
 
}