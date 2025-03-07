#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n; cin >> n;
    v<bool> used(n,false);
    int a, ptr = 0;
    F0R(i,n) {
        cin >> a;
        if (used[a-1]) { // used next unused number
            used[ptr] = 1; 
            cout << ptr+1 << ' ';
        } else { // use current number
            used[a-1] = 1;
            cout << a << ' ';
        } while (used[ptr]) {ptr++;} // find next unused number
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}