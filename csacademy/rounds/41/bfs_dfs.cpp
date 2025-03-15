#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vec<int> bfs(n), dfs(n);
    F0R(i,n) {cin >> bfs[i];}
    F0R(i,n) {cin >> dfs[i];}
    
    if (n>1 && bfs[1]!=dfs[1]) {cout << -1;}
    else {
        cout << 2*(n-1)-1 << '\n';
        F0R(i,n-1) {cout << 1 << ' ' << bfs[i+1] << '\n';}
        F0R(i,n-2) {cout << dfs[i+1] << ' ' << dfs[i+2] << '\n';}
    }
}